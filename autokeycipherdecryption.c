#include<stdio.h>
#include<string.h>

void main()
{
	char plaintext[100];
	char key[100];
	char ciphertext[100];

	int len1,len2,len3;
	int i=0,j=0;
	
	printf("Enter the cipher text");
	scanf("%s",ciphertext);
	
	printf("Enter the key");
	scanf("%s",key);

	len1=strlen(ciphertext);
	len2=strlen(key);

	if(len2<len1)
	{
		for(i=len2;i<len1;i++,j++)
		{
			key[i]=ciphertext[j];
		}
			key[i]='\0';
	}
	
	printf("key=%s",key);
	printf("\n");
	int d;
	j=len2;

	for(i=0;i<len1;i++,j++)
	{
		d=ciphertext[i]-(key[i]-97);
		
		if(d<97)
		{
			d=d+26;
			plaintext[i]=d;
			key[j]=plaintext[i];
		}
		else
		{
			plaintext[i]=d;
			key[j]=plaintext[i];
		}
	}
	plaintext[i]='\0';
	printf("plaintext=%s",plaintext);

	
}

