#include<stdio.h>
#include<string.h>

char straight[100];
char reverse[100];
int findrow(char x);
int findcolumn(char x);
void main()
{
	char plaintext[100];
	char key[100];
	char ciphertext[100];
	char table[26][26];
	

	int i,j,k,l,r,d=97;
	k=0;l=0;

	for(i=122;i>=97;i--,k++)
	{
		l=0;
		for(j=i;j>=97;j--,l++)
		{
			table[k][l]=j;
			printf("%c ",table[k][l]);
		}
		for(r=122;r>i;r--,l++)
		{
			table[k][l]=r;
			printf("%c ",table[k][l]);
		}
		printf("\n");
	}
	
	for(i=0;i<26;i++)
	{
		straight[i]=d++;
		//printf("%c\n",straight[i]);
	}
	//printf("i=%d",i);
	straight[i]='\0';
	//printf("straight=%s",straight);
	d=d-1;
	for(j=0;j<26;j++)
	{
		reverse[j]=d--;
	}
	reverse[i]='\0';
	printf("\n");
	//printf("straight=%s",straight);
	//printf("\nreverse=%s",reverse);
	printf("Enter the plain text");
	scanf("%s",plaintext);
	printf("Enter the key");
	scanf("%s",key);

	int len1=strlen(plaintext);
	int len2=strlen(key);
	
	int row,column;
	j=0;
	for(i=0;i<len1;i++,j++)
	{
		row=findrow(key[j]);
		column=findcolumn(plaintext[i]);
		ciphertext[i]=table[row][column];
		printf("%c %d %d\n",ciphertext[i],row,column);
		if(j==len2-1)
		{
			j=-1;
		}
		
	}
	ciphertext[i]='\0';
	printf("\n%s",ciphertext);
	
	
}

int findrow(char x)
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

int findcolumn(char x)
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



