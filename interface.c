#include "final.h"


void create_db() {
    int semid;
    int shmid;
    semid = semget(SEMKEY, 1, IPC_CREAT | IPC_EXCL | 0644);
    if (errno)
    {
        access_db();
        return;
    } else {
        union semun us;
        us.val = 1;
        semctl(semid, 0, SETVAL, us);
        printf("semaphore created\n");
    }

    shmid = shmget(SHMKEY, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0644);
    printf("shared memory created\n");

    semid = semget(SEMKEY, 1, 0);
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(semid, &sb, 1);
    shmid = shmget(SHMKEY, SHM_SIZE, 0);

    struct user_info * db = shmat(shmid, NULL, 0);
    shmdt(db);
    sb.sem_op = 1;
    semop(semid, &sb, 1);
}

void access_db() {
    int semid = semget(SEMKEY, 1, 0);
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(semid, &sb, 1);
    int shmid = shmget(SHMKEY, SHM_SIZE, 0);
    struct user_info *db = shmat(shmid, NULL, 0);
    shmdt(db);
    sb.sem_op = 1;
    semop(semid, &sb, 1);
}

int signup(char * usr, char * pwd) {
    // printf("running signup!\n");
    int semid = semget(SEMKEY, 1, 0);
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(semid, &sb, 1);
    int shmid = shmget(SHMKEY, SHM_SIZE, 0);
    struct user_info *db = shmat(shmid, 0, 0);
    struct user_info *copy = db;
    while(db->usr[0]){
        if(db->usr[0] && !strcmp(db->usr, usr)){
            shmdt(copy);
            sb.sem_op = 1;
            semop(semid, &sb, 1);
            return 1;
        }
        db++;
    }
    strcpy(db->usr, usr);
    strcpy(db->pwd, pwd);
    db->is_active = 0;

    shmdt(copy);
    sb.sem_op = 1;
    semop(semid, &sb, 1);
    return 0;
}

int signin(char * usr, char * pwd) {
    int semid = semget(SEMKEY, 1, 0);
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(semid, &sb, 1);
    int shmid = shmget(SHMKEY, SHM_SIZE, 0);
    struct user_info *db = shmat(shmid, 0, 0);
    struct user_info *copy = db;
    int is_auth = 0;

    while(db->usr[0]) {
        if(db->usr[0] && !strcmp(db->usr, usr)){
            if(!strcmp(db->pwd, pwd)) {
                db->is_active = 1;
                is_auth = 1;
                break;
            }
        }
        db++;
    }

    shmdt(copy);
    sb.sem_op = 1;
    semop(semid, &sb, 1);
    if(is_auth)
        return 0;
    return 1;
}

int signout(char * usr) {
    int semid = semget(SEMKEY, 1, 0);
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(semid, &sb, 1);
    int shmid = shmget(SHMKEY, SHM_SIZE, 0);
    struct user_info * db = shmat(shmid, 0, 0);
    struct user_info * copy = db;

    while(db->usr[0]) {
        if(!strcmp(db->usr, usr)){
            db->is_active = 0;
            break;
        }
        db++;
    }

    shmdt(copy);
    sb.sem_op = 1;
    semop(semid, &sb, 1);
    return 0;
}