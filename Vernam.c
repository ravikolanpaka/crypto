#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char pt[100];
char et[100];
char dt[100];
char pad[100]; 
char gram[80]; 
int r,k=0;
int option,size=0,count=0;
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
void evalues()
{ 
 int i=0;
 size=0;
 getchar();
 /*while(pad[i]!='\0')
 {
   pad[i]=' ';
   i++;
 }*/
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
 //printf("Size of the Text->%d\n",size);
 i=0;
 assign(); 
 while(i!=size)
 {
  ran();
  i++;
 }
/* printf("PlainText %s\n",pt);
 printf("Size of the Text %d\n",size);
 printf("Grammar %s\n",gram);
 printf("PaddedText %s\n",pad);*/
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
 printf("---------------------------------------------------------------\n"); 
 printf("Encrypted Text: %s\n",et);
 printf("One Time Pad: %s\n",pad);
 printf("Plain Text: %s\n",dt);
 printf("---------------------------------------------------------------\n"); 
}
void encrypt()
{
 count=0;
 int it=0,siz=0; 
 //printf("Plain Text -> %s\n",pt);
 for(it=0;it<size;it++)
 {
  et[it]=' ';
 }
 for(it=0;pt[it]!='\0';it++)
 {
   siz++;
   et[it] = (pt[it] ^ pad[it]);    
   //if(it>17) printf("%d ",et[it]);
  // printf("Encrypted Text ->%c\n",et[it]);
 } 
 //printf("%d ",et[18]);
 /*for(it=0;et[it]!='\0';it++)
 { 
   printf("Value of it is %d\n",it);
 }*/
 //printf("---------------------------------------------------------------\n"); 
 printf("---------------------------------------------------------------\n"); 
 printf("Plain Text: %s\n",pt);
 printf("One Time Pad: %s\n",pad);
 printf("Encrypted Text: ");

 //printf("Plain Text -> %s\n",pt);
 //printf("One Time Pad Used -> %s\n",pad); 
 //printf("\nEncrypted Text -> %s\n",et);
 /*for(it=0;et[it]!='\0';it++)
 {
  siz++;
 }*/
 //printf("Size of the encrypted text %d\n",siz); 
 print();
 printf("\n"); 
 printf("---------------------------------------------------------------\n"); 
/* printf("---------------------------------------------------------------\n"); 
 for(it=0;et[it]!='\0';it++)
 {
  dt[it] = et[it]^pad[it];
 }
 printf("Decrypted Text-> %s\n",dt);*/
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
   evalues();
   encrypt();
  }
  else if(option==2)
  {
   dvalues();    
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
