#include<stdio.h>

void main()
{
	int i,j,k,l;

	char key[100];
	FILE *fp;
	
	
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
					fprintf(fp,"%s ",key);
				}
			}
		}
	}
}
