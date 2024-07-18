#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

extern float etime();
sem_t sema;//semaphore declaration
int m;//# of threads that has to be created 
int N = 400;//fixed matrix size
int c[400][400], a[400][400], b[400][400];//declaring all 3 matrices

void *worker(void *arg){
    long tid = (long) arg;
    int start = (N/m)*tid, end = (N/m)*(tid+1);//initializing  the start and the end of matrix 'a'
   
    for (int i = start; i < end; i++){//'i' to itirate through the rows
        for (int j = 0; j < N; j++){//'j' to itirate through the column
            c[i][j] = 0;//matrix to store the final matrix
            for (int k = 0; k < N; k++){//'k' to itirate through the posotion of the element in mstrix 'c' 
                c[i][j] += a[i][k] * b[k][j];//matrix multiplication
            }
        }
    }
    sem_post(&sema);//semaphore posting
}

int main(int argc, char *argv[]){
    m= atoi(argv[1]);//conversion to string
    pthread_t t[m];
    long i;
    sem_init(&sema,0,0);//initializing semaphore
    
    if (argc != 2){
        printf("Error!: Expected 1 argument, but got %d\n", argc - 1 );//to check the number of paramaters
    }
 
    etime();//calling etime
    
    for (int j = 0; j < N; j++){//'j' to itirate through the column
    	for (int k = 0; k < N; k++){//'k' to itirate through the posotion of the element in mstrix 'c' 
    		a[j][k] = 1;
    		b[j][k] = 1;//initializing the matrices to '1'
    	}
    }
    
    for (i = 0; i < m; i++) {
        pthread_create(&t[i], NULL, worker, (void*)i);//creating thread
    }
    
    for (i = 0; i < m; i++) {
        sem_wait(&sema);//semaphore waiting
    }

    
    float new_time = etime();
    printf("Elapsed time:%f\n",new_time);
}
