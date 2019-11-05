#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void signalhandler(int);


int main()
{
    FILE *fptr = fopen("Logfile.txt","w");// to reset the file everytime open the program
    fprintf(fptr,"");
    fclose(fptr);

    char *command;
    char *arg[100];

    while(1){
    printf("Shell¬$ ");
    gets(command); //take input from the user

    if(strlen(command) == 0){ //to handle the enter only
        printf("\n");
        continue;
    }

    //*************SPLIT STRING INTO SPACES *****************
     char *ptr_arg = strdup(command); //delimeter the command by space
                 for(int i = 0;i< sizeof(arg);i++)
                 {
                    arg[i] = strsep(&ptr_arg," "); //split string into spaces
                    if(arg[i] == NULL){
                        break;
                    }
                 }

    if(strcmp(command,"exit") == 0){
        exit(0);
    }

    else{


        pid_t childID = fork();

        if(childID >=0){    //fork success
            if(childID !=0){    //parent process
                if(arg[1] != NULL)
                if(strcmp(arg[1],"&") != 0)
                wait(NULL); // wait for the child process

                if(arg[1] == NULL){
                wait(NULL);
                }

                printf("parent ID = %d \n",getppid());
                sleep(0.5); //to appear the shell after the print of child
            }
            else{   //child process
                printf("Executing Child\n");
                printf("Child ID = %d \n",getpid());        //return the id of the child
                printf("Child parent ID = %d \n",getppid()); //getppid return the id of parent of the process

                if(arg[1] != NULL)        // to delete the & beacuse firefox don't go to page called and
                if(strcmp(arg[1],"&") == 0){
                    arg[1] = NULL;
                }

                 printf("%s\n",arg[0]);

                 if(execvp(arg[0],arg)<0){
                    printf("couldn't execute command \n");
                }
                //else baynfezhaa
            }

            signal(SIGCHLD, signalhandler); // to handle the termination of every process
        }
        else{                       //fork failed to create child process and exit
            printf("Failed to create child process \n");
            exit(0);
        }
    }

    }
    return 0;
}

 void signalhandler(int signal)
    {
        pid_t pid = wait(NULL); //returns process ID of the terminated child process

        FILE *fptr = fopen("Logfile.txt","a");

        fprintf(fptr,"Child process was terminated %d \n",pid); //the number of signal of process terminated

        killpg(pid,signal);// to kill the proces when it's terminated and don't enter the zombie mode

        fclose(fptr);
    }
