#include<stdio.h>
#include<string.h>

void main()
{
	char plaintext[100];
	char ciphertext[100];

	int i=0,j=0,d=97;
	
	char straight[100];
	char reverse[100];

	for(i=0;i<26;i++)
	{
		//printf("***");
		straight[i]=d++;
		//printf("%c\n",straight[i]);
		
	}
	straight[i]='\0';

	//printf("\n%s",straight);
	d--;
	for(i=0;i<26;i++)
	{
		reverse[i]=d--;
	}
	reverse[i]='\0';
	
	//printf("\n%s",reverse);

	printf("Enter the plain text");
	scanf("%s",plaintext);

	int len1=strlen(plaintext);

	for(i=0;i<len1;i++)
	{
		for(j=0;j<26;j++)
		{
			if(plaintext[i]==straight[j])
			{
				//printf("%c\n",reverse[j]);
				ciphertext[i]=reverse[j];
			}
		}
	}

	ciphertext[i]='\0';
	printf("ciphertext=%s\n",ciphertext);
	
	
	
}

