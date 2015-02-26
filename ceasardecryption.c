#include<stdio.h>
#include<string.h>
void main()
{
	char plaintext[100];
	char ciphertext[100];
	
	printf("Enter the cipher text");
	scanf("%s",ciphertext);
	
	int k,i=0;
	int d;
	int len1=strlen(ciphertext);
	
	for(k=0;k<26;k++)
	{
	
		printf("%d ",k);
		
		for(i=0;i<len1;i++)
		{
			d=ciphertext[i]-k;
			if(d<97)
			{
				d=d+26;
				plaintext[i]=d;
			}
			else
			{
				plaintext[i]=d;
			}
			
		}
		plaintext[i]='\0';

		printf("%s",plaintext);
		printf("\n");
		
	}	
}
