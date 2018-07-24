/*0 6 0 0 5 1
6 0 3 0 0 5
0 3 0 6 0 6
0 0 6 0 2 4
5 0 0 2 0 5
1 5 6 4 5 0
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Int_max 999999
int *t;

void main()
{
    int **ar,j,i=1,n,v,u,min=Int_max,count=1,mincount=0;
    printf("\nEnter the no vertex ");
    scanf("%d",&n);n++;
    ar=(int **)malloc(n*sizeof(int *));
    t=(int*)calloc(n,sizeof(int));
    printf("\nEnter the cost matrix\n");
    for(j=0;j<n;j++)
    {
       ar[j]=(int *)malloc(n*sizeof(int));
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            scanf("%d",&ar[i][j]);
            t[j]=0;
			if(ar[i][j]==0)
                ar[i][j]=Int_max;
        }
    }
    t[1]=1;
	while(count<n-1)
    {

		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
            {
				if(t[i]&&ar[i][j]<min)
                {
				    min=ar[i][j];
					v=j;
					u=i;
                }
            }
		}
		if(!t[u] || !t[v])
		{
			printf("\n%d. Edge(%d ,%d) = %d",count,u,v,min);
			mincount+=min;
			count++;
			t[v]=1;
		}
        ar[u][v]=Int_max;
		ar[v][u]=Int_max;
		min=Int_max;
    }
    printf("\nThe cost of spaning tree is %d",mincount);
}
