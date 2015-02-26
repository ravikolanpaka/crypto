#include<stdio.h>
#include<string.h>

void main()
{
	char plaintext[100];
	char key[100];
	char ciphertext[100];

	int i=0,j=0,d=97;
	
	char straight[100];
	char reverse[100];
	
	for(i=0;i<26;i++)
	{
		straight[i]=d++;
	}
	straight[i]='\0';

	d--;
	
	for(i=0;i<26;i++)
	{
		reverse[i]=d--;
	}
	reverse[i]='\0';

	printf("Enter the cipher text");
	scanf("%s",ciphertext);

	int len1=strlen(ciphertext);
	
	for(i=0;i<len1;i++)
	{
		for(j=0;j<26;j++)
		{
			if(ciphertext[i]==reverse[j])
			{
				plaintext[i]=straight[j];
			}
		}
	}
	
	plaintext[i]='\0';
	printf("Plaintext=%s",plaintext);
}
