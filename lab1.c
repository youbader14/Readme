//Answers to the two questions are all the way at the bottom.
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
static void* child(void *ignored){
//infinite for loop
for(;;){
//waits 3 seconds before executuiing the next line of code
sleep(3);
//print statement
printf("Child is done sleeping 3 seconds. \n");
}
return NULL;
}

int main(int argc, char *argv[]){
   //creates new thread 
   pthread_t child_thread;
   int code;
   int rcode;
   char user_input = 0 ;
   //initializing the new thread
   code = pthread_create(&child_thread, NULL, child, NULL);
   //output error message if failed to create thread
   if(code){
      fprintf(stderr, "pthread_create failed with code %d\n", code);
   }
   sleep(5);
   //print statment that runs in parallele with the child thread
   printf("Parent is done sleeping 5 seconds.\n");
   printf("please press enter to terminate the child thread \n");
   //get input from user
   user_input = getchar(); 
   //checks for the right input from the user
   if(user_input =='\n')
    {
        //terminate the child thread 
        rcode = pthread_cancel(child_thread);
        //tells the user that the thread has been terminatd
        printf("Child thread was terminated\n");
    }
    else{
        printf("wrong input\n");
    }
   return 0;
}
/*
*1) In this program pthread is used to run two threads in parallel the child thread runs after 3 seconds and prints a message
*then the main thread executes after 5 seconds and also prints a message, asking the user to press enter while the main thread 
*is waiting for the users input, the child thread keeps executing.

*2)the child thread keeps executing since its in an infinite loop and isnt yet terminated, only when the user presses the enter key
*that the child thread is terminated.
*/