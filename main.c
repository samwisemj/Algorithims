//MERGE SORT
#include <stdio.h>
#include <conio.h>
void merge(int ar[], int l, int mid, int u)
{
    int *temp=(int *)malloc((u-l+1)*sizeof(int));
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=u)
    {
        if(ar[i]<=ar[j])
        {
            temp[k]=ar[i];
            i++;
        }
        else
        {
            temp[k]=ar[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
        temp[k++]=ar[i++];
    while(j<=u)
        temp[k++]=ar[j++];
    for(i=l,k=0;k<(u-l+1);k++,i++)
        ar[i]=temp[k];
}

void split(int ar[], int l, int u)
{
    int mid =(l+u)/2;
    split(ar,l,mid);
    split(ar,mid+1,u);
    merge(ar,l,mid,u);
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
