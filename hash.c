#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char word[100];
	struct node *next;
}*temp,*new;

void insert(char *word);

struct node *table[100];
int hash(char *word);
void main()
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

	printf("\nprinting the values\n");
	
	for(i=0;i<100;i++)
	{
		if(table[i]!=NULL)
		{
			temp=table[i];
			printf("%d\t",i);
			while(temp->next!=NULL)
			{
				printf("(%s)->",temp->word);
				temp=temp->next;
			}
			printf("(%s)->",temp->word);
			printf("\n");
		}
		else
		{
			printf("%d\n",i);
		}
	}
}

void insert(char *word)
{
	int val=hash(word);

	printf("val=%d\n",val);
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
