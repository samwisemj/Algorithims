#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *visited;
	int i,ptr,j,f=1,top=-1,n,stack[20];
	int **ar;
	printf("Enter the no of nodes in graph\n");
	scanf("%d",&n);n++;
	visited=(int *)calloc(n,sizeof(int));
	ar=(int **)malloc((n)*sizeof(int *));
	for(i=0;i<n;i++)
		ar[i]=(int *)malloc(n*sizeof(int));
	printf("Enter adjecency matrix\n");
	for(i=1;i<n;i++)
		for(j=1;j<n;j++)
			scanf("%d",&ar[i][j]);
	printf("Enter starting node\n");
	scanf("%d",&ptr);

	i=ptr;stack[++top]=ptr;visited[ptr]=1;j=1;
	printf("DFS IS \n %d\t",ptr);

	while(top>-1)
	{
		for(j=1;j<n;j++)
		{
			if(ar[i][j]==1&&!visited[j])
			{
				visited[j]=1;
				i=j;
				stack[++top]=j;
				printf("%d\t",j);
				//j=0;
			}
		}
		i=stack[top--];
	}
	for(i=1;i<n;i++)
       if(visited[i]==0)
           f=0;
    if(f==0)
            printf("\nDisconnected Graph");
        else
            printf("\nConnected graph");
}
/*0 1 0 0 1 0
1 0 1 1 0 0
0 1 0 1 0 1
0 1 1 0 0 0
1 0 0 0 0 1
0 0 1 0 1 0*/

/*0 1 0 0 1 0 0
1 0 1 1 0 0 0
0 1 0 1 0 1 0
0 1 1 0 0 0 0
1 0 0 0 0 1 0
0 0 1 0 1 0 0
0 0 0 0 0 0 0*/
/*
starting node 1,dfs is 1 2 3 4 6 5
        _5--------6
      _-          |
    1-_     _4_   |
       -_  -   - _|
          2-------3
*/
