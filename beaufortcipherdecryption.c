#include<stdio.h>
#include<string.h>


int findrow(char x,char *reverse);
int findcolumn(char x,char *straight);
void main()
{
	char straight[100];
	char reverse[100];
	char plaintext[100];
	char key[100];
	char ciphertext[100];
	char beautable[26][26];
	
	int i,j,k,l,r,d=97;
	k=0;l=0;
	
	for(i=122;i>=97;i--,k++)
	{
		l=0;
		for(j=i;j>=97;j--,l++)
		{
			beautable[k][l]=j;
			printf("%c ",beautable[k][l]);
		}
		for(r=122;r>i;r--,l++)
		{
			beautable[k][l]=r;
			printf("%c ",beautable[k][l]);
		}
		printf("\n");
	}

	for(i=0;i<26;i++)
	{
		straight[i]=d++;
		//printf("%c\n",straight[i]);
	}
	straight[i]='\0';

	d=d-1;
	for(j=0;j<26;j++)
	{
		reverse[j]=d--;
	}
	reverse[i]='\0';
	printf("\n");
	
	printf("Enter the cipher text");
	scanf("%s",ciphertext);

	printf("Enter the key");
	scanf("%s",key);

	int len1=strlen(ciphertext);
	int len2=strlen(key);
	int row,column;
	j=0;
	
	for(i=0;i<len1;i++,j++)
	{
		row=findrow(key[j],reverse);
		column=findcolumn(ciphertext[i],straight);
		plaintext[i]=beautable[row][column];
		printf("%c %d %d\n",plaintext[i],row,column);
		if(j==len2-1)
		{
			j=-1;
		}
		
	}
	plaintext[i]='\0';
	
	printf("plaintext=%s\n",plaintext);
}

int findrow(char x,char *reverse)
{
	int i=0;
	for(i=0;i<26;i++)
	{
		if(reverse[i]==x)
		{
			return i;
			break;
		}
	}
}

int findcolumn(char x,char *straight)
{
	int i=0;
	for(i=0;i<26;i++)
	{
		if(straight[i]==x)
		{
			return i;
			break;
		}
	}
}

