#include<stdio.h>
#include<string.h>
void main()
{
	char plaintext[100];
	char key[100];
	char ciphertext[100];

	int len1,len2,len3;
	int i=0,j=0;
	
	printf("Enter the plain text");
	scanf("%s",plaintext);

	printf("Enter the key");
	scanf("%s",key);

	 len1=strlen(plaintext);
	 len2=strlen(key);
	printf("%d %d",len1,len2);	
	if(len2<len1)
	{
		for(i=len2;i<len1;i++,j++)
		{
			key[i]=plaintext[j];
			
		}

		key[i]='\0';
	}
		
	printf("\nkey=%s",key);
	printf("\n");

	int d;
	for(i=0;i<len1;i++)
	{
		d=key[i]+(plaintext[i]-97);
		
		//printf("%d\n",d);
		if(d>122)
		{
			d=d-26;
			ciphertext[i]=d;
			//printf("%c %c %c  ()()()\n",key[i],plaintext[i],ciphertext[i]);
		}
		else
			ciphertext[i]=d;
	}
	ciphertext[i]='\0';

	printf("%s",ciphertext);
}
