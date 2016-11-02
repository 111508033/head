/*<head command.

    Copyright (C) 2016  "nagesh"

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

void verbose();
int help();
int display_file(int, char*);
int display_byte(char * file, int num);



int main(int argc, char * argv[])
{
    FILE    *   fp;             // file pointer
    char    *   line = NULL;
    int         *len  = 0;
 	char *str;
 	char *cstr;
    int cnt = 0, c, cnum;    
 	
 	    if( argc < 3)
    {
        printf("Insufficient Arguments!!!\n");
        printf("Please use \"program-name file-name N\" format.\n");
        return -1;
    }
    
 	if(argc == 3) {
    	//For displaying --help option
    	if((strcmp("--help", argv[2]))==0){
			// open file
    		fp = fopen("help.txt","r");
 
    		// checking for file is exist or not
    		if( fp == NULL ) {
		        printf("\n%s file can not be opened !!!\n",argv[2]);
        	return 1;   
    		}
 
    		// read lines from file one by one
    
 
    		while (getline(&line, &len, fp) != -1) {
        		printf("%s",line); fflush(stdout);
    		}
    		// close file
    		fclose(fp);
 		}
 		else
    	// open file
    	display_file(10, argv[2]); 		
	}
	
	else if(argc > 3 || argc < 5){
		//For displaying --help option
		if((strcmp("--help", argv[2]))==0)
			help();
		//For displaying --verbose option
		else if((strcmp("--verbose", argv[2]))==0){
			verbose(argv[3]);
			display_file(10, argv[3]);
		}
		else if((strcmp("-v", argv[2]))==0) {	
			verbose(argv[3]);
			display_file(10, argv[3]);
		}
		else if((strcmp("-c", argv[2]))==0) {
			//strcpy(cstr, argv[2]);
			//printf("%s", cstr);
			cnum = atoi(argv[3]);
			//printf("%d", cnum);
			display_byte(argv[4], cnum);
		}
	}
	return 0;
}

int display_byte(char * file, int num){
	
	FILE *fp3;
	char c;
	fp3 = fopen(file, "r");
	if(fp3 == NULL) {
      perror("Error in opening file");
      return(-1);
   }
   do {
      c = fgetc(fp3);
      printf("%c", c);
      num--;
   }while(num != 0);

	fclose(fp3);
}
int help() {
	FILE * fp2;
	char * line = NULL;
	int *len = 0;
			// open file
    		fp2 = fopen("help.txt","r");
 
    		// checking for file is exist or not
    		if( fp2 == NULL ) {
		        printf("Could not display content. Try again!\n");
        	return 1;   
    		}
 
    		// read lines from file one by one
    
 
    		while (getline(&line, &len, fp2) != -1) {
        		printf("%s",line); fflush(stdout);
    		}
    		// close file
    		fclose(fp2);

}

void verbose(char * file){
	printf("==> %s <==\n", file);
}

int display_file(int cnt, char * file) {
    FILE    *   fp1;             // file pointer
    char    *   line = NULL;
    int         *len  = 0, inc;

	fp1 = fopen(file,"r");
 
    	// checking for file is exist or not
    	if( fp1 == NULL ) {
        	printf("\n%s file can not be opened !!!\n",file);
        	return 1;   
    	}
 
    	// read lines from file one by one
    
 
    	while (getline(&line, &len, fp1) != -1) {
        	inc++;
        	if ( inc > cnt) 
            	break;
         	printf("%s",line); fflush(stdout);
    	}
    	// close file
    	fclose(fp1);
}


