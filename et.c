#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>

extern float etime();
char *buf;
int size;//global variable to compare the string

void  *dummy(void *ptr){
    char *p = (char *) ptr;
    if (strcmp(p, "-a")==0){//string comparison with '-a' value
        for (int i=0;i<size;i+=4096){//i+=4096 for icrementing it k times
            buf[i]='x';//modify the buffer
        }
    }
}

int main(int argc, char *argv[]){   
     pthread_t t;
     
     if (argc != 3){
        printf("Error!: Expected 2 arguments, but got %d\n", argc - 1 );//to check the number of paramaters
    }
     
    size=atoi(argv[2])*1024;//conversion to string
    buf=(char*)(calloc(size, 1));//buffer allocation with calloc
    
    etime();//calling etime

    if (strcmp(argv[1], "-b")==0){//string conparison with '-b' value
        for (int i=0;i<size;i+=4096){//i+=4096 for incrementing it 4k times
            buf[i]='x';//modify the buffer
        }
    }

    pthread_create(&t, NULL, dummy, argv[1]);//thread creation
    pthread_join(t, NULL);//thread joining

    float e = etime();
    printf("elapsed time:%f\n",e);
    }

    
