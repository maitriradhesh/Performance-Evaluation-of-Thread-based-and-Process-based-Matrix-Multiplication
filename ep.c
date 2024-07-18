#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> 

extern float etime();

int main(int argc, char *argv[]){   
    pid_t cpid;

    if (argc != 3){
        printf("Error!: Expected 2 arguments, but got %d\n", argc - 1 );//to check the number of paramaters
    }

    int size = atoi(argv[2])*1024;//conversion to string
     char* buf = (char*) calloc(size, 1);

    etime();//calling etime()

    if (strcmp(argv[1], "-b") == 0){ //string comparison for '-b' value
        for (int i = 0; i < size; i += 4096) {//i+=4096 for incrementing it 4k times
            buf[i] = 'x';//modify the buffer
            }
    }

    if(cpid = fork() == 0){//child process
        if (strcmp(argv[1], "-a") == 0){ //srting comparison for '-a' value
        for (int i = 0; i < size; i += 4096){//i+=4096 for incrementing it 4k times
            buf[i] = 'x';//modify the buffer
            }
        }
        exit(0);//must
    }
    else{// parent process
            waitpid(cpid,NULL,0);
        }
        
        float new_time = etime();
        printf("elapsed time:%f\n",new_time);

    }
