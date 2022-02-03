#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  

int main() 
{ 
    FILE * fp;
    int pass, r_pass ;  //pass for given user, r_pass for given file
    int pid, pid1, pid2, pid3; 
    pid = fork(); 
  
    if (pid == 0) { 
	printf("Parent process --> pid = %d\n", getppid());
	printf("child[1] --> pid = %d and parent id = %d\n", getpid(), getppid());
	printf("File was created... \n");
	fp = fopen ("opSys.txt", "w+");
	fclose(fp);
    } 
    else { //Parent Part
	wait(NULL); // // Wait for C1 of P1 
        pid1 = fork(); // This created new child[2]
        if (pid1 == 0) { 
            pid2 = fork();  //I divided the child[2], so this provides grandchild
		if (pid2 == 0){
		  sleep(3);
		  printf("child[4] --> pid = %d and parent id = %d\n", getpid(), getppid());
		  printf("Say me password.. \n");
		}
		else {
		  wait(NULL); // Wait for C4 of C2
		  printf("child[2] --> pid = %d and parent id = %d\n", getpid(), getppid());
		  printf("Write key : ");
		  scanf ("%d", &pass);
		  fp = fopen ("opSys.txt", "w+");
		  fprintf(fp, "%d", pass);
		  fclose(fp);
		}
        } 
        else { 
	wait (NULL); 
	pid3 = fork();
		if(pid3 == 0) { //Third Child Part
			//sleep(10);
			printf("child[3] --> pid = %d and parent id = %d\n", getpid(), getppid());
			fp = fopen ("opSys.txt", "r");
		  	fscanf(fp, "%d", &r_pass);  //Reading value from file
		  	fclose(fp);
			if(r_pass == getppid()){
			  printf("****MATCHED****\n");
			}
			else {
			 printf("****NOT MATCHED**** \n");
			}	
		} 
		else {
			wait(NULL);
			printf("Parent process --> pid = %d\n", getpid(), getppid());
			printf("Program finished.. \n");
		}
	} 
    } 
  
    return 0; 
} 
