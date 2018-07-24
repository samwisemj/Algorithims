#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *visited;
	int i,front,rear,ptr,j,n,queue[20];
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
	front=-1;rear=0;
	i=ptr;visited[i]=1;j=1;
	//queue[rear++]=i;
	printf("BFS IS \n %d\t",ptr);
	while(front<rear)
	{
		for(j=1;j<=n;j++)
		{
			if(ar[i][j]==1&&!visited[j])
			{
				visited[j]=1;
				queue[rear++]=j;
				printf("%d\t",j);
			}
		}
        i=queue[++front];
	}
}
/*0 1 0 0 1 0
1 0 1 1 0 0
0 1 0 1 0 1
0 1 1 0 0 0
1 0 0 0 0 1
0 0 1 0 1 0


starting node 1,bfs is 1 2 5 3 4 6
        _5--------6
      _-          |
    1-_     _4_   |
       -_  -   - _|
          2-------3
*/



