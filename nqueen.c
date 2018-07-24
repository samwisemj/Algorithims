#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
char **ar;
int n;
void input();
int check(char **ar,int row,int col);
int nq(char **ar,int col);
void main()
{
	int i,j;
	//clrscr();
	input();
	if(nq(ar,0)==1)
	{
		for(i=0;i<n;i++)
		{	printf("\n\t");
			for(j=0;j<n;j++)
			{	printf("%c ",ar[i][j]);
			}
		}
	}
	else printf("Solution doesnt exist");
	getch();
}
void input()
{
	int i,j;
	printf("Enter the no of queens : ");
	scanf("%d",&n);
	ar=(char **)calloc(n,sizeof(char *));
	for (i = 0; i < n; i++)
		ar[i]=(char *)calloc(n,sizeof(char));
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) ar[i][j]='_';
}
int nq(char **ar,int col)
{
	int i;
	if(col>=n) return 1;//base case
	for(i=0;i<n;i++)
	{
		if(check(ar,i,col)==1)
		{
			ar[i][col]='Q';
			if(nq(ar,col+1)==1)
				return 1;
			ar[i][col]='_';
		}
	}
	return 0;
}
int check(char **ar,int row,int col)
{
	int i,j;
	for(i=row,j=col;i>=0,j>=0;j--,i--)//left top diagonal
	{if (ar[i][j]=='Q') return 0;}
	for(i=row,j=col;i<n,j>=0;i++,j--) //r8 bottom diagonal
	{if (ar[i][j]=='Q') return 0;}
	for(i=row,j=col;j>=0;j--)        //sideways
	{if (ar[i][j]=='Q') return 0;}
	return 1;
}
