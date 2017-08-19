#include "string.h"
#include "stdio.h"
#include "stdlib.h"

char out[100][100]={0};
char out2[100][100]={0};
char S1[100]={0};
char S2[100]={0};
char cal[100][2]={0};
char temp[100][100]={0};

int MAX(int a,int b)
{
	if(a>b)
       return a;
	else
	   return b;
}
int mi,mj,num,c;
int recursion()
{         
    int i,j; 
    for(i=cal[c][1];i>0;i--)
    {    
        for(j=cal[c][2];j>0;j--)
        {
            if(out[i][j]==num && num!=0)
            {
                num-=1;cal[c][1]-=1;cal[c][2]-=1;
                temp[c][num]=S1[i-1];
                recursion(); 
            } 
        }     
    }
}
void main()
{
	int x,y,i,j,c1,c2,m,t=1,k=1,l=1,max,maxnum=0,n=0;

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
            {
                out[i][j]=out[i-1][j-1]+1;	
                out2[i][j]=1;
                printf("  %d",out[i][j]);		
            }
            else	
            {
                out[i][j]=MAX(out[i-1][j],out[i][j-1]);	
                out2[i][j]=0;
                printf("  %d",out[i][j]);
            }
        }	
        printf(" %c\n",S1[i-1]);
	}
	max=out[x][y];
	
	//2表结合
	printf("\n");
	for(j=0;j<y;j++)
	printf("  %c",S2[j]);
	printf("\n");
	for(i=1;i<x+1;i++)
	{
        for(j=1;j<y+1;j++)
        {
            out[i][j]=out[i][j]*out2[i][j];
            if(out[i][j]==max)
                {
                    maxnum++;
                    cal[maxnum][1]=i;
                    cal[maxnum][2]=j;
                }
            printf("  %d",out[i][j]);
        }
        printf(" %c\n",S1[i-1]);
	}
	printf("  max = %d  maxnum = %d\n",max,maxnum);
    for(c=1;c<maxnum+1;c++)
    { 
	    num=max;
        printf("\n c = %d",c); 
        recursion();
        printf("\n");
        for(i=0;i<max;i++)
            printf(" %c ",temp[c][i]);        
    }
    printf("\n结束\n");
}


 
