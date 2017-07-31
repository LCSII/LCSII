#include "string.h"
#include "stdio.h"

char out[100][100]={0};
char S1[100]={0};//列
char S2[100]={0};//行	
char com1[100]={0};
char com2[100]={0};

int MAX(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int x,y,i,j,c1,c2,n=0;
	printf("Input S1:");
	scanf("%s",S1);
	printf("Input S2:");
	scanf("%s",S2);
	x=strlen(S1);
	y=strlen(S2);	
	printf("x = %d,y = %d\n",x,y);
	for(j=0;j<y;j++)
	printf("  %c",S2[j]);
	printf("\n");
	
	//列表
	for(i=1;i<x+1;i++)
	{
		for(j=1;j<y+1;j++)
		{
			if(S1[i-1]==S2[j-1])
				out[i][j]=out[i-1][j-1]+1;			
			else	
				out[i][j]=MAX(out[i-1][j],out[i][j-1]);			
			printf("  %d",out[i][j]);
		}	
		printf(" %c\n",S1[i-1]);
	}
	
	//提取最后一列和最后一行
	for(i=1;i<x+1;i++)
			if(out[i][y]>out[i-1][y])
				com1[n++]=S1[i-1];
	c1=strlen(com1);
	printf("com1 = %s\n",com1);
	n=0;
	for(j=1;j<y+1;j++)
		if(out[x][j]>out[x][j-1])
			com2[n++]=S2[j-1];
	c2=strlen(com2);
	printf("com2 = %s\n",com2);
	//校验
	n=0;
	for(i=0;i<x;i++)
		if(S1[i]==com1[n])
			n++;
	if(n==c1)
	{
		n=0;
		for(j=0;j<y;j++)
			if(S2[j]==com1[n])
				n++;
		if(n==c2)
			printf("%s\n",com1);
	}
	
	n=0;
	for(i=0;i<x;i++)
		if(S1[i]==com2[n])
			n++;
	if(n==c1)
	{
		n=0;
		for(j=0;j<y;j++)
			if(S2[j]==com2[n])
				n++;
		if(n==c2)
			printf("%s\n",com2);
	}
	printf("\n");
}





