#include "final.h"


int create_db() {
    int semid;
    int shmid;
    semid = semget(SEMKEY, 1, IPC_CREAT | IPC_EXCL | 0644);
    if (semid < 0)
    {
        printf("error - cannot create semaphore: %s\n", strerror(errno));
        return errno;
    } else {
        union semun us;
        us.val = 1;
        semctl(semid, 0, SETVAL, us);
        printf("semaphore created\n");
    }

    shmid = shmget(SHMKEY, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0644);
    if (shmid < 0)
    {
        printf("error - cannot create shared memory: %s\n", strerror(errno));
        return errno;
    }
    printf("shared memory created\n");

    semd = semget(SEMKEY, 1, 0);
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(semd, &sb, 1);
    shmid = shmget(MEMKEY, SEG_SIZE, 0);

    struct user_info ** db = shmat(shmid, NULL, 0);
    shmdt(db);
    sb.sem_op = 1;
    semop(semid, &sb, 1);
}

// int signup(char * usr, char * pwd) {

// }

// int login() {

// }

// int logout() {

// }

// int generate_id() {

// }