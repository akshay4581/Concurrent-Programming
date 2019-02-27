#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//The threads start printing without waiting for other threads to be created.
#define NUM_THREADS 8

void *hello(void *ID){
  printf("%d: Hello World\n", *(int *)ID);

}

/**
int main(int argc, char *argv[]) {
     pthread_t threads[NUM_THREADS];
     int rc, t;
     for(t=0;t<NUM_THREADS;t++)
     {    printf("Creating thread %d\n", t);
          rc = pthread_create(
                &threads[t],
                NULL,
                hello,
                (void *)&t);

          if (rc){
               printf("ERROR %d",rc);
               exit(-1);
          }
      }
      //Waits for the children to terminate.
       pthread_exit(NULL);

}

Output
Creating thread 0
Creating thread 1
1: Hello World
Creating thread 2
2: Hello World
Creating thread 3
3: Hello World
Creating thread 4
4: Hello World
Creating thread 5
Creating thread 6
6: Hello World
6: Hello World
Creating thread 7
7: Hello World
8: Hello World

To avoid data race we need to use other data type like an array.
**/
int main(int argc, char *argv[]) {
     pthread_t threads[NUM_THREADS];
     int id[NUM_THREADS];
     int rc, t;
     for(t=0;t<NUM_THREADS;t++)
     {    printf("Creating thread %d\n", t);
          id[t] =t;
          rc = pthread_create(
                &threads[t],
                NULL,
                hello,
                &id[t]);

          if (rc){
               printf("ERROR %d",rc);
               exit(-1);
          }
      }
      //Waits for the children to terminate.
       pthread_exit(NULL);

}

