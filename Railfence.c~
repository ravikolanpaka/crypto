#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char elem[100];
char delem[100];
int fours=0,twos=0,threes=0,siz=0,space=0;
int option=0;
void size(char a[])
{
 int i;
 siz=0;
 for(i=0;a[i]!='\0';i++)
 siz+=1;
}
void inputs()
{
    getchar();
    printf("Enter the text to encrypt\n");
    scanf("%[0-9a-zA-Z ]s",elem);    
}
void four()
{
    int i;
    for(i=0;i<siz;i++)
    {
        fours+=1;
        i+=3;
    }
}
void two()
{
    int i;
    for(i=1;i<siz;i++)
    {
        twos+=1;
        i+=1;
    }
}
void three()
{
    int i;
    for(i=2;i<siz;i++)
    {
        threes+=1;
        i+=3;
    }
}
int spacing()
{
 int i = (fours-1)*4+1;
 int j = (twos-1)*2+2;
 int k = (threes-1)*4+3;
 if(i>j && i>k) return i;
 else if(j>i && j>k) return j;
 else if(k>i && k>j) return k;
}
void encrypt()
{
   int i,k=0;
   char matrix[3][space]; 
   printf("---------------------------------------------------------------\n"); 
   printf("Plaintext: %s\n",elem);
   printf("Ciphertext: ");
   for(i=0;i<siz;i++)
   {
       matrix[0][i] = elem[k];
       printf("%c",matrix[0][i]);
       k+=4;
       i+=3;
   }   
   k=1;
   for(i=1;i<siz;i++)
   {       
       matrix[1][i] = elem[k];
       printf("%c",matrix[1][i]);
       k+=2;
       i+=1;
   }
   k = 2;
   for(i=2;i<siz;i++)
   {
       matrix[2][i] = elem[k];
       printf("%c",matrix[2][i]);
       k+=4;
       i+=3;
   }
  printf("\n");          
  printf("---------------------------------------------------------------\n"); 
}
void decrypt()
{
  int i,k=0,row=0;
  int count[3]={0,0,0};
  int value[3]={0,1,2};
  getchar();
  printf("Enter the text to decrypt\n");
  scanf("%[0-9a-zA-Z ]s",delem);    
  printf("---------------------------------------------------------------\n"); 
  printf("Ciphertext: %s\n",delem);
  printf("Plaintext: ");
  size(delem);
  four();
  two();
  three();
  spacing();
  char matrix[3][siz];     
  for(i=0;i<siz;i++)
  {
   matrix[0][i] = delem[k];
   k++;
   i+=3; 
  }
  for(i=1;i<siz;i++)
  {
   matrix[1][i] = delem[k];  
   k++;
   i+=1; 
  }
  for(i=2;i<siz;i++)
  {
   matrix[2][i] = delem[k];   
   k++;
   i+=3; 
  }  
  for(i=0;i<space;i++)  
  {
    printf("%c",matrix[row][value[row]]);    
    if(row==0) value[row]+=4;
    else if(row==1) value[row]+=2;
    else if(row==2) value[row]+=4;
    count[row]+=1;
    if(row==1)
    {
      if(count[row]%2==0)
      row = 0;
      else row = 2;
    }
    else if(row==2)
    {
      row = 1;
    }
    else row++;
  }
  printf("\n");
  printf("---------------------------------------------------------------\n"); 
}
int main()
{
  while(1)
  {
  printf("---------------------------------------------------------------\n"); 
  printf("Please select an option from the following\n");
  printf("---------------------------------------------------------------\n"); 
  printf("1.Encrypt plain text\n");
  printf("2.Decrypt cipher text\n");
  printf("3.Exit the application\n");
  printf("---------------------------------------------------------------\n"); 
  scanf("%d",&option);
  if(option==1)
  { 
   inputs();
   size(elem);
   four();
   two();
   three(); 
   space = spacing();
   encrypt();
  }
  else if(option==2)
  { 
   decrypt();  
  }
  else if(option==3)
  {
   exit(1);
  }
  else 
  {
   printf("Sorry , the entered option is invalid\n");
   printf("---------------------------------------------------------------\n"); 
   printf("Please select an option from the following");
   printf("---------------------------------------------------------------\n"); 
   printf("1.Encrypt plain text");
   printf("2.Decrypt cipher text");
   printf("---------------------------------------------------------------\n"); 
  }
  }
  return 1;
}
