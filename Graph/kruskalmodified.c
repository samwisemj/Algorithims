#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
   int u,v,w;
}edge;
void swap(edge *a,edge *b)
{
    edge temp=*a;
    *a=*b; *b=temp;
}
/*int getpivot(edge *ar,int l,int r)
{
    int p=l;
    while(l<r)
    {
        while(ar[p].w<ar[r].w && p<r) r--;
        if(p<r && ar[p].w>ar[r].w)
            {swap(&ar[r],&ar[p]); p=r, l++;}
        while(ar[p].w>ar[l].w && p>l) l++;
        if(p>l && ar[p].w<ar[l].w)
            {swap(&ar[l],&ar[p]); p=l, r--;}
    }
    return p;
}*/
int getpivot(edge ar[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
    int pivot;
    int i = p - 1;
    int j;
    pivot = ar[pivotIndex].w;
    swap(&ar[pivotIndex], &ar[r]);
    for (j = p; j < r; j++)
    {
        if (ar[j].w < pivot)
        {
            i++;
            swap(&ar[i], &ar[j]);
        }

    }
    swap(&ar[i+1], &ar[r]);
    return i + 1;
}

void split(edge *ar,int l,int r)
{
    int p;
    if(l<r)
    {
       p=getpivot(ar,l,r);
       split(ar,l,p-1);split(ar,p+1,r);
    }
}
int *parent;
int find(int x)
{
  while(parent[x])
        x=parent[x];
  return x;
}
int main()
{
    int i,n,m,e1,e2,mst=0,count=0;
    edge *ar;
    //printf("\nEnter the no of vertex");
    scanf("%d",&n);
    //printf("\nEnter the no of edges");
    scanf("%d",&m);
    ar=(edge *)malloc(m*sizeof(edge));
    parent=(int*)calloc(n,sizeof(int));
   // printf("Enter u v w for edges");
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&ar[i].u,&ar[i].v,&ar[i].w);
    }
    split(ar,0,m-1);
    scanf("%d",&e1);
    for(i=0;count<n-1;i++)
    {
        e1=find(ar[i].u);
        e2=find(ar[i].v);
        if(e1!=e2)
        {
            mst+=ar[i].w;
            parent[e1]=e2;
            count++;
        }
    }
    printf("%d",mst);return 0;
}
