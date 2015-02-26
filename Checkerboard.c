#include <stdio.h>
#include <stdlib.h>
char matrix[30]="e taoin srf hkgbcdjlmpquvwxyz#";
char pt[100];
char et[200];
char dt[200];
int option=0;
void einputs()
{
 int j=0;
 int k1=0;
 getchar();
 printf("Enter text to encrypt\n"); 
 scanf("%[0-9a-zA-Z ]s",pt);  
 for(j=0;pt[j]!='\0';j++)
  {
   if((int)pt[j]>=48 && (int)pt[j]<=57) 
  {
   dt[k1] = '#'; 
   k1++;
   dt[k1] = pt[j];
   k1++;
  }
  else
  {
   dt[k1] = pt[j];
   k1++;
  }
  }
}
void dinputs()
{
 int j=0;
 getchar(); 
 for(j=0;pt[j]!='\0';j++)
  {
   pt[j]=' ';
  }
 for(j=0;et[j]!='\0';j++)
  {
   dt[j]=' ';
  }
 for(j=0;et[j]!='\0';j++)
  {
   et[j]=' ';
  }
 printf("Enter text to decrypt\n"); 
 scanf("%[0-9 ]s",et);   
}
void encrypt()
{
 int i=0,j=0,k=0;
 for(j=0;dt[j]!='\0';j++)
  {
   if((int)dt[j]>=48 && (int)dt[j]<=57) 
   {
    et[k] = dt[j];
    k++;
   }
   else
  {
   for(i=0;i<30;i++)
   {
      if((int)dt[j]==(int)matrix[i] || (((int)dt[j])+32)==(int)matrix[i] || (int)dt[j]==(((int)matrix[i])+32))
      {
        if(i>=0 && i<=9)
          {
           if(i!=1 && i!=7) 
           {
            et[k] = i+48;  
            k++; 
           }
           else if(i==1 || i==7)
           {
            et[k] = '1';  
            k++; 
            et[k] = '1';  
            k++; 
           } 
          }
        else if(i>=10 && i<=19)
          {	   
            et[k] = '1'; 
            k++;
            et[k] = (i%10)+48; 
            k++;
          }
        else if(i>=20 && i<=29)
          {	   
            et[k] = '7'; 
            k++;
            et[k] = (i%10)+48; 
            k++;          
          }            
        break;
      }
   }
  }
 }
 printf("---------------------------------------------------------------\n"); 
 printf("PlainText: %s\n",pt); 
 printf("CipherText: %s\n",et); 
 printf("---------------------------------------------------------------\n"); 

}
void decrypt()
{
 int j;
 int k = 0; 
 for(j=0;et[j]!='\0';j++)
  {   
   if(((int)et[j])!=49 && ((int)et[j])!=55 && ((int)et[j])>=48 && ((int)et[j])<=57)
    {
     pt[k] = matrix[(int)et[j]-48];
     k++;
    }
   else if(((int)et[j])==49) 
    {
     if(et[j+1]!='\0')
     {      
      pt[k] = matrix[(((int)et[j+1]+1)-48+9)];
      j++;
      k++;
     } 
     else if(et[j+1]=='\0')
     {
      printf("Error while sending the messasge\n");
      exit(0);
     }
    } 
  else if(((int)et[j])==55) 
   {
    if(et[j+1]!='\0')
    {
      if(et[j+1]=='9')
      {
        j+=2; 
        pt[k] = et[j];
        k++;   
      }
      else
      {
	pt[k] = matrix[(((int)et[j+1]+1)-48+19)];
        j++;
        k++;
      }        
    }
    else if(et[j+1]=='\0')
     {
      printf("Error while sending the messasge\n");
      exit(0);
     } 
   }
  }
 printf("---------------------------------------------------------------\n"); 
 printf("CipherText: %s\n",et); 
 printf("PlainText: %s\n",pt); 
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
   einputs();
   encrypt();
  }
  else if(option==2)
  { 
   dinputs();
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
