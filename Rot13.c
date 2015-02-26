#include <stdio.h>
#include <stdlib.h>
char pt[100];
char cp[100];
char dt[100];
int option;
void encrypt()
{
 int i;
 printf("Enter the plain text\n");
 getchar();
 scanf("%[0-9a-zA-Z!@#$%^&*()-+/_=,.? ]s",pt);
 for(i=0;pt[i]!='\0';i++)
 {
  if(((int)pt[i]>=65 && (int)pt[i]<=90))
  {
    cp[i] = (char)(((((int)pt[i])+13-65)%26)+65); 
  }  
  else if(((int)pt[i]>=97 && (int)pt[i]<=122))
  {
   cp[i] = (char)(((((int)pt[i])+13-97)%26)+97); 
  }  
  
  else
  {
  cp[i] = pt[i];
  }
 }
 printf("---------------------------------------------------------------\n"); 
 printf("PlainText: %s\n",pt); 
 printf("CipherText: %s\n",cp); 
 printf("---------------------------------------------------------------\n"); 
}
void decrypt()
{
 int i;
 printf("Enter the cipher text\n");
 getchar();
 scanf("%[0-9a-zA-Z!@#$%^&*()-+/_=,.? ]s",pt);
 for(i=0;pt[i]!='\0';i++)
 {
   if(((int)pt[i]>=65 && (int)pt[i]<=90))
  {
   if((((int)pt[i])-13-65)>0)
    {
     dt[i] = (char)(((((int)pt[i])-13-65))+65); 
    }
   else
    {
     dt[i]=(char)(91+(((int)pt[i])-13-65));
    }
  }
  else if(((int)pt[i]>=97 && (int)pt[i]<=122))
  {
   if((((int)pt[i])-13-97)>=0)
    {
     dt[i] = (char)(((((int)pt[i])-13-97))+97); 
    }
   else
    {
     dt[i]=(char)(123+(((int)pt[i])-13-97));
    }
  }
  else
  {
    dt[i] = pt[i];
  }
 }
 printf("---------------------------------------------------------------\n"); 
 printf("CipherText: %s\n",pt); 
 printf("PlainText: %s\n",dt); 
 printf("---------------------------------------------------------------\n"); 
}
int main(int argv,char *args)
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
  encrypt();  
  }
  else if(option==2)
  { 
  decrypt();  
  }
  else if(option==3)
  exit(1);
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
