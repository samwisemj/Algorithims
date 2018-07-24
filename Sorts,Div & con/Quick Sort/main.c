#include <stdio.h>
#include <stdlib.h>
int getpivot(int ar[],int l, int r)
{
    int p=l,temp;
    while(l<r){
	while(p<r&&ar[p]<ar[r])
        r--;
    if(p<r && ar[p]>ar[r])
    {
        temp=ar[p];
        ar[p]=ar[r];
        ar[r]=temp;
        p=r;
        //l++;
    }
    while(p>l&&ar[p]>ar[l])
        l++;
    if(p>l&&ar[p]<ar[l])
    {
        temp=ar[p];
        ar[p]=ar[l];
        ar[l]=temp;
        p=l;
       // r--;
    }}

    return p;
}
void split(int ar[],int l,int r)
{
    int p;
    if(l<r)
    {
        p=getpivot(ar,l,r);
        split(ar,l,p-1);
        split(ar,p+1,r);
    }
}
int main()
{
    int n,*ar,i;
    printf("Enter the no of elements you want in the array\n");
    scanf("%d",&n);
    ar =(int *)malloc(n*sizeof(int));
    printf("Enter the array elements you want in the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    split(ar,0,n-1);
    printf("Sorted Array");
    for(i=0;i<n;i++)
        printf("%d\t",ar[i]);
    getch();
    return 0;
}

