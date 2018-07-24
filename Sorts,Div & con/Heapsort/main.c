#include <stdio.h>
#include <stdlib.h>
void swap(int *a ,int *b){ int temp=*a;*a=*b;*b=temp;}
void upheapify(int ar[],int ind)
{
    int par=(ind-1)/2;
    //if(ind==0)
      //  return;
    while(ar[par]<ar[ind])
    {
        swap(&ar[par],&ar[ind]);
        ind=par;
        par=(ind-1)/2;
    }
}
void downheapify(int ar[],int ind)
{
    int par=0;
    int lc=(par*2)+1,rc=(par*2)+2;
    while(1)
    {
        if(rc<=ind && ar[rc]>ar[par] && ar[rc]>ar[lc])
            {
                swap(&ar[rc],&ar[par]);
                par=rc;
            }
        else if(lc<=ind && ar[lc]>ar[par])
            {
                swap(&ar[lc],&ar[par]);
                par=lc;
            }
        else
            break;
        lc=(par*2)+1;
        rc=(par*2)+2;
    }
}
void heapsort(int ar[], int n)
{
    int i=0,index=n;
    for(i=0;i<n;i++)
    {
        swap(&ar[0],&ar[index]);
        index--;
        downheapify(ar,index);
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
    {
        scanf("%d",&ar[i]);
        upheapify(ar,i);
    }
    heapsort(ar,n-1);
    printf("Sorted Array\n");
    for(i=0;i<n;i++)
        printf("%d\t",ar[i]);
    getch();
    return 0;
}
