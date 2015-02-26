#include<stdio.h>
#include<string.h>

void main()
{
	char plaintext[100];
	char key[100];
	char ciphertext[100];
	
	int len1,len2,i=0;
	
	printf("Enter the cipher text");
	scanf("%s",ciphertext);
	
	printf("Enter the key");
	scanf("%s",key);
	
	len1=strlen(ciphertext);
	len2=strlen(key);

	int j=0;
	
	printf("%d %d",len1,len2);

	if(len2<len1)
	{
		for(i=len2;i<len1;i++,j++)
		{
			key[i]=key[j];
			if(j==len2-1)
			{
				j=-1;
			}	
			//printf("%c %d",key[i],i);		
		}
		key[i]='\0';
	}

	printf("%s",key);
	printf("\n");

	int d;
	for(i=0;i<len1;i++)
	{
		d=ciphertext[i]-(key[i]-97);
		
		//printf("%d\n",d);
		if(d<97)
		{
			d=d+26;
			plaintext[i]=d;
			//printf("%c %c %c  ()()()\n",key[i],plaintext[i],ciphertext[i]);
		}
		else
			plaintext[i]=d;
	}
	plaintext[i]='\0';

	printf("%s",plaintext);
	
}
