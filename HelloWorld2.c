#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//The threads start printing without waiting for other threads to be created.
#define NUM_THREADS 8

void * hello(){
  printf("Hello World\n");
  return NULL;
}


int main(int argc, char *argv[]) {
     pthread_t threads[NUM_THREADS];
     int rc, t;
     for(t=0;t<NUM_THREADS;t++)
     {    printf("Creating thread %d\n", t);
          rc = pthread_create(
                &threads[t],
                NULL,
                hello,
                NULL);

        //  if (rc){
      //         printf("ERROR %d",rc);
    //           exit(-1);
  //        }
      }
      //Waits for the children to terminate.
       pthread_exit(NULL);

}

