#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char word[100];
	struct node *next;
}*temp,*new;

struct node *table[100];

char key[100];
char plaintext[100];	
char ciphertext[100];

int hash(char *word);
void insert(char *word);
void vigenere(char *ciphertext);
void decrypt(char *key,char *ciphertext);
void hashing();
void search(char *plaintext);
void ceasar(char *ciphertext);

void main()
{	
	
	
	printf("Enter the cipher text");
	scanf("%s",ciphertext);
	hashing();
	vigenere(ciphertext);
	ceasar(ciphertext);
	
	
	
}

void vigenere(char *ciphertext)
{

	printf("vigenere cipher\n");
	int i,j,k,l,m,n;

	//printf("hello");
	
	
	
	for(i=97;i<=122;i++)
	{
		for(j=97;j<=122;j++)
		{
			for(k=97;k<=122;k++)
			{
				for(l=97;l<=122;l++)
				{
					
	
							key[0]=i;
							key[1]=j;
							key[2]=k;
							key[3]=l;
							key[4]='\0';
							decrypt(key,ciphertext);
						
					
				}
				
			}
			
		}
					
	}
}

void decrypt(char *key,char *ciphertext)
{

	int len1,len2,i=0,j=0;
	len1=strlen(ciphertext);
	len2=strlen(key);
	//printf("\n%s %s",ciphertext,key);
	//printf("len1=%d len2=%d",len1,len2);
	
	//printf("\n%s %s",ciphertext,key);
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

	//printf("\n%s %s ",key,ciphertext);
	//printf("\n");

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
	search(plaintext);
	//printf("%s %s %s\n",key,ciphertext,plaintext);
		
}

void hashing()
{
	FILE *fp;
	fp=fopen("dictionary.txt","r");
	char word[100];

	int i=0;
	
	for(i=0;i<100;i++)
	{
		table[i]=NULL;
	}

	while(fscanf(fp,"%s",word)!=EOF)
	{
		insert(word);
	}

	//printf("\nprinting the values\n");

	for(i=0;i<100;i++)
	{
		if(table[i]!=NULL)
		{
			temp=table[i];
			//printf("%d\t",i);
			while(temp->next!=NULL)
			{
				//printf("(%s)->",temp->word);
				temp=temp->next;
			}
			//printf("(%s)->",temp->word);
			//printf("\n");
		}
		else
		{
			//printf("%d\n",i);
		}
	}
}

void insert(char *word)
{
	int val=hash(word);

	//printf("val=%d\n",val);
	new=(struct node *)malloc(sizeof(struct node));
	strcpy(new->word,word);
	new->next=NULL;
	
	if(table[val]==NULL)
	{
		table[val]=new;
	}
	else
	{
		new->next=table[val];
		table[val]=new;
	}
}

int hash(char *word)
{
	int i=0,sum=0;

	for(i=0;word[i]!='\0';i++)
	{
		sum=sum+word[i];
	}

	return sum%100;
}

void search(char *plaintext)
{
	int val=hash(plaintext);
	int flag=0;
	
	if(table[val]!=NULL)
	{
		temp=table[val];
		while(temp->next!=NULL)
		{
			if(strcmp(temp->word,plaintext)==0)
			{
				printf("%s\n",plaintext);
			}
			temp=temp->next;
		}
			if(strcmp(temp->word,plaintext)==0)
			{
				printf("%s\n",plaintext);
			}
	}
}

void ceasar(char *ciphertext)
{

	printf("ceasar cipher \n");
	int k,i=0;
	int d;
	int len1=strlen(ciphertext);

	for(k=0;k<26;k++)
	{
	
		//printf("%d ",k);
		
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
	
		search(plaintext);
		
	}
}


