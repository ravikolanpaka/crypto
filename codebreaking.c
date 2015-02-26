#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct node
{
	char word[100];
	struct node *next;
}*temp,*new;

struct node *table[100];

char key[100];
char plaintext[100];	
char ciphertext[100];
char pt[100];
char et[100];
char dt[100];
char pad[100]; 
char gram[80]; 
int r,k=0;
int option,size=0,count=0;


int hash(char *word);
void insert(char *word);
void vigenere(char *ciphertext);
void decrypt(char *key,char *ciphertext);
void hashing();
void search(char *plaintext);
void ceasar(char *ciphertext);
void atbash(char *ciphertext);
void autokey(char *ciphertext);
void autodecrypt(char *key,char *ciphertext);
int findrow(char x,char *reverse);
int findcolumn(char x,char *straight);
void beaufort(char *ciphertext);
void beaudecrypt(char *key,char *ciphertext);
void rot13(char *ciphertext);
void vernam();
void print();
void assign();
void dvalues();
void ran();
void encrypt();
void evalues();
FILE *fp1;
void main()
{	
	
	FILE *fp;
	fp=fopen("ciphers.txt","r+");
	fp1=fopen("time2.txt","w+");
	
	while(fscanf(fp,"%s",ciphertext)!=EOF)
	{
		hashing();
		vigenere(ciphertext);
		//ceasar(ciphertext);
		//atbash(ciphertext);
		//autokey(ciphertext);
		//beaufort(ciphertext);	
		//rot13(ciphertext);
		//vernam();
		fprintf(fp1,"%c",'\n');
		
	}
}

void vigenere(char *ciphertext)
{

	clock_t time1,time2;
	double time;

	time1=clock();
	printf("*******vigenere cipher*******\n");
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
					for(m=97;m<=122;m++)
					{			
					
	
							key[0]=i;
							key[1]=j;
							key[2]=k;
							key[3]=l;
							key[4]=m;
							key[5]='\0';						
								
							decrypt(key,ciphertext);
					}
				}
			}		
			
		}
					
	}

	time2=clock();
	time=(time2-time1)/CLOCKS_PER_SEC;
	fprintf(fp1,"timevigenere=%lf ",time);
	
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
	//printf("in search ciphertext=%s\n",plaintext);
	int val=hash(plaintext);
	int flag=0;
	
	if(table[val]!=NULL)
	{
		//printf("hello");
		temp=table[val];
		while(temp->next!=NULL)
		{
			
			if(strcmp(temp->word,plaintext)==0)
			{
				//printf("hii");
				printf("%s\n",plaintext);
			}
			temp=temp->next;
		}
			if(strcmp(temp->word,plaintext)==0)
			{
				//printf("jiji");
				printf("%s\n",plaintext);
			}
	}
}

void ceasar(char *ciphertext)
{

	clock_t time1,time2;
	double time;
	time1=clock();
	printf("*******ceasar cipher*******\n");
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
	time2=clock();
	time=(time2-time1)/CLOCKS_PER_SEC;
	fprintf(fp1,"ceasartime=%lf ",time);
}

void atbash(char *ciphertext)
{
	clock_t time1,time2;
	double time;
	time1=clock();
	char straight[100];
	char reverse[100];
	printf("*******atbash cipher*******\n");
	int i=0,j=0,d=97;
	
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
	search(plaintext);
	time2=clock();
	time=(time2-time1)/CLOCKS_PER_SEC;
	fprintf(fp1,"timeatbash=%lf ",time);
}

void autokey(char *ciphertext)
{

	clock_t time1,time2;
	double time;
	time1=clock();
	printf("*******autokey cipher*******\n");
	int i,j,k,l,m;

	for(i=97;i<=122;i++)
	{
		for(j=97;j<=122;j++)
		{
	
			for(k=97;k<=122;k++)
			{
				for(l=97;l<=122;l++)
				{
					for(m=97;m<=122;m++)
					{			
					
	
							key[0]=i;
							key[1]=j;
							key[2]=k;
							key[3]=l;
							key[4]=m;
							key[5]='\0';						
								
							decrypt(key,ciphertext);
					}
				}
			}		
			
		}
					
	}


	time2=clock();
	time=(time2-time1)/CLOCKS_PER_SEC;
	fprintf(fp1,"timeautokey=%lf ",time);
	
	
}

void autodecrypt(char *key,char *ciphertext)
{
	int len1,len2,len3;
	int i=0,j=0;
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

	search(plaintext);
	
}

void beaufort(char *ciphertext)
{
	clock_t time1,time2;
	double time;
	time1=clock();
	printf("*******beaufort cipher*******\n");

	int i,j,k,l,m;

	for(i=97;i<=122;i++)
	{
		for(j=97;j<=122;j++)
		{
	
			for(k=97;k<=122;k++)
			{
				for(l=97;l<=122;l++)
				{
					for(m=97;m<=122;m++)
					{			
					
	
							key[0]=i;
							key[1]=j;
							key[2]=k;
							key[3]=l;
							key[4]=m;
							key[5]='\0';						
								
							decrypt(key,ciphertext);
					}
				}
			}		
			
		}
					
	}

	time2=clock();
	time=(time2-time1)/CLOCKS_PER_SEC;
	fprintf(fp1,"timebeafort=%lf ",time);
	
}

void beaudecrypt(char *key,char *ciphertext)
{

	
	char straight[100];
	char reverse[100];	
	char beautable[26][26];
	int i,j,k,l,r,d=97;
	k=0;l=0;

	for(i=122;i>=97;i--,k++)
	{
		l=0;
		for(j=i;j>=97;j--,l++)
		{
			beautable[k][l]=j;
			//printf("%c ",beautable[k][l]);
		}
		for(r=122;r>i;r--,l++)
		{
			beautable[k][l]=r;
			//printf("%c ",beautable[k][l]);
		}
		//printf("\n");
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

	int len1=strlen(ciphertext);
	int len2=strlen(key);
	int row,column;
	j=0;

	for(i=0;i<len1;i++,j++)
	{
		row=findrow(key[j],reverse);
		column=findcolumn(ciphertext[i],straight);
		plaintext[i]=beautable[row][column];
		//printf("%c %d %d\n",plaintext[i],row,column);
		if(j==len2-1)
		{
			j=-1;
		}
		
	}
	//printf("key=%s,plaintext=%s",key,plaintext);
	plaintext[i]='\0';
	search(plaintext);
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

void rot13(char *ciphertext)
{
	clock_t time1,time2;
	double time;
	time1=clock();
	printf("*********rot13 cipher*********\n");
	int i;
	for(i=0;ciphertext[i]!='\0';i++)
 	{
  		 if(((int)ciphertext[i]>=65 && (int)ciphertext[i]<=90))
 		 {
   			if((((int)ciphertext[i])-13-65)>0)
    			{
    					 plaintext[i] = (char)(((((int)ciphertext[i])-13-65))+65); 
   		        }
   			else
  			{
  					plaintext[i]=(char)(91+(((int)ciphertext[i])-13-65));
   			}
  		}
		else if(((int)ciphertext[i]>=97 && (int)ciphertext[i]<=122))
  		{
   			if((((int)ciphertext[i])-13-97)>=0)
    			{
     				plaintext[i] = (char)(((((int)ciphertext[i])-13-97))+97); 
    			}
   			else
   			{
     				plaintext[i]=(char)(123+(((int)ciphertext[i])-13-97));
    			}
  		}
		else
  		{
    			plaintext[i] = ciphertext[i];
  		}
	}

	search(plaintext);
	time2=clock();
	time=(time2-time1)/CLOCKS_PER_SEC;
	fprintf(fp1,"timerot13=%lf ",time);
}

void vernam()
{
	clock_t time1,time2;
	double time;
	time1=clock();
	printf("******Vernam Cipher*******\n");
	printf("Encrypt plain text\n");
	evalues();
   	encrypt();
	printf("Decrypt cipher text\n");
	dvalues();
	time2=clock();
	time=(time2-time1)/CLOCKS_PER_SEC;
	fprintf(fp1,"timevernam=%lf ",time);
	
}

void evalues()
{ 
 	int i=0;
 	size=0;
 	getchar();

 	for(i=0;i<size;i++)
 	{
  		pt[i]=' ';
 	} 
 	k = 0;
 	i=0;
 	printf("Enter the plain text\n");
 	scanf("%[a-zA-Z0-9 ]s",pt); 
 	while(pt[i]!='\0')
 	{
 		size++;
 		i++;
 	}
 
 	i=0;
 	assign(); 
 	while(i!=size)
 	{
  		ran();
  		i++;
 	}

}

void encrypt()
{
 	count=0;
 	int it=0,siz=0; 
 
 	for(it=0;it<size;it++)
 	{
  		et[it]=' ';
 	}
 	for(it=0;pt[it]!='\0';it++)
 	{
   		siz++;
   		et[it] = (pt[it] ^ pad[it]);    
  	} 
 	//printf("---------------------------------------------------------------\n"); 
 	printf("Plain Text: %s\n",pt);
 	printf("One Time Pad: %s\n",pad);
 	printf("Encrypted Text: ");

  
 	print();
 	printf("\n"); 
 	//printf("---------------------------------------------------------------\n"); 
}

void ran()
{  
 	r = rand();
 	while(!(r>0 && r < 62))
 	{
 		r = r/7;
 	}  
 	pad[k] = gram[r];
 	k++;
}

void dvalues()
{ 
 	int i=0,coun=0,acount=0,value,p=0;
 	char ar[3];
 	getchar(); 
 	for(i=0;i<size;i++)
	{
   		et[i]=' ';
 	}
 	i =0;
 	for(i=0;i<size;i++)
 	{
   		pad[i]=' ';
 	}
 	printf("Enter the text to decrypt\n"); 
 	scanf("%[a-zA-Z0-9# ]s",et);
 	getchar();
 	printf("Enter the pad used to decrypt\n"); 
 	scanf("%[a-zA-Z0-9 ]s",pad);
 	printf("Decryption Encrypted Text%s\n",et);
 	printf("Decryption Padded Text%s\n",pad);
 	for(i=0;et[i]!='\0';i++)
 	{   
   		for(p=0;p<3;p++)
   		{ 
    			ar[p]=' ';
   		}
   		if(et[i]!='#')
   		{
    			dt[coun] = et[i]^pad[coun];
    			coun++;
   		}
   		else if(et[i]=='#')
   		{	    
    			i++;
    			acount = 0;
    			while(et[i]!='#')
   			{
    				ar[acount] = et[i];
    				acount++;
    				i++;
   			}
   			value = atoi(ar);  
   			dt[coun] = value^pad[coun]; 
  	 		coun++; 
   		}
 	}
 	//printf("---------------------------------------------------------------\n"); 
 	printf("Encrypted Text: %s\n",et);
 	printf("One Time Pad: %s\n",pad);
 	printf("Plain Text: %s\n",dt);
 	//printf("---------------------------------------------------------------\n"); 
}

void assign()
{
 	int i=65,j=0;
 	for(i=65;i<=90;i++)
 	{
  		gram[j] = i;
  		j++;
 	}
 	for(i=97;i<=122;i++)
 	{
  		gram[j] = i;
  		j++;
 	}
 		gram[j] = ' ';
 		j++;
 	for(i=48;i<=57;i++)
 	{
  		gram[j] = i;
  		j++;
 	}
}


void print()
{
 	int i;
 	for(i=0;i<size;i++)
 	{
  		if((et[i] > 64 && et[i] < 91) || (et[i] > 96 && et[i] < 123) || (et[i] >= 48 && et[i] <= 57) || et[i] == 32)
  		{
   			printf("%c",et[i]);
  		}
  		else
  		{
   			printf("%c",'#');
   			printf("%d",et[i]);
   			printf("%c",'#');
  		}
 	}
}


