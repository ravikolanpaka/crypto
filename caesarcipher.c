#include<stdio.h>
#include<string.h>
void main()
{
	char plaintext[100];
	char ciphertext[100];

	printf("Enter the plaintext");
	scanf("%s",plaintext);
	
	int k,i=0;
	int d;
	int len1=strlen(plaintext);
	for(k=0;k<26;k++)
	{
	
		printf("%d ",k);
		
		for(i=0;i<len1;i++)
		{
			d=plaintext[i]+k;
			if(d>122)
			{
				d=d-26;
				ciphertext[i]=d;
			}
			else
			{
				ciphertext[i]=d;
			}
			
		}
		ciphertext[i]='\0';

		printf("%s",ciphertext);
		printf("\n");
		
	}	
}

	
