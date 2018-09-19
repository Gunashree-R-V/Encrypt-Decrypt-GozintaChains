#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "gozinta.h"
int char_num [256];
char num_char[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

/*	Function to initailise the array char_num	*/
void initialize()
{
	int j=0;
	for(int i=97;i<=122;i++,j++)
		char_num[i]=j;
	for(int i=65;i<=90;i++,j++)
		char_num[i]=j;
	for(int i=48;i<=57;i++,j++)
		char_num[i]=j;
	/*for(int i=48;i<=127;i++)
		printf("%d\t\n",char_num[i]);
	*/
}

/*	Function that encrypts the given file with the given key and encrypted file saved as encrypt.txt in current working directory	*/
void encoder(char *file1 , int key[], int len)
{
	int c;
	FILE *file;
	file = fopen(file1, "r");
	int fd = open("encrypt.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	
	if (fd==-1)
	{
		printf("Error\n");
	}
	
	if (file) {
		int i;
		for (c = getc(file),i=0;c != EOF;c = getc(file),i=(i+1)%len) // putchar(c); fclose(file);
		{
			
			char ec=c;
			if( !isspace(c) )
			{
				ec=num_char[(char_num[c]+key[i])%62];
			}
			
			 			
			int sz = write(fd, &ec, 1);
			printf("%c",ec); 
					
		}
		
    		fclose(file);
	      
	}

}


/*	Function that decrypts the given file with the given key	*/
void decoder(char *file1 , int key[], int len)
{
	int c;
	FILE *file;
	file = fopen(file1, "r");
	if (file) {
		int i;
		for (c = getc(file),i=0;c != EOF;c = getc(file),i=(i+1)%len) // putchar(c); fclose(file);
		{
			char ec=c;
			if( !isspace(c) )
			{
				int j;
				for(j=0;j<62;j++)
				{
					if (num_char[j]==c)
						break;
				}
				
				if ((j-key[i])<0)
				{
					int index=j-key[i];
					while (index<0)index+=62;
					ec=num_char[(index)%62];
					//printf(" %c \n",ec);
				}
				else
				{
					ec=num_char[(j-key[i])%62];
				}
			}
			
			printf("%c",ec); 			
			
					
		}
    		fclose(file);
	      
	}

}


/*	Main function	*/
void main(int argc , char *argv[])
{
	int len;
	int prev = 0;
	initialize();
	int *shiftKey = (int *)calloc(sizeof(int),1);

	if(argc != 4)
	{
		fprintf(stderr,"Usage: \n ./encoder file-name key 0(encryption)/1(decryption)\n");
		exit(0);
		
	}
	char *file = argv[1];
	char *key = argv[2];
	int flag = atoi(argv[3]);
	
	if(access(file,F_OK) != 0)
	{
		fprintf(stderr , "%s : No such file or directory \n",file);
		exit(0);
	}
	
	for(int i=0 ; i<strlen(key) ; ++i)
	{
		int *k=maxiGozinta(key[i],&len);		
		shiftKey = realloc(shiftKey , sizeof(int)*(len+prev));
		for(int j=0 ; j<len ; ++j)
		{
			shiftKey[prev+j] = k[j];
		}
		prev = prev + len;
	}
	if(flag == 0)
	{
		encoder(file,shiftKey,prev);
	}
	else
		decoder(file,shiftKey,prev);

	//return 0;
}


