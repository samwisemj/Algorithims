#include <stdio.h>
#include <stdlib.h>
typedef struct str
{
    int max,min;
}var;
var* minmax(int ar[],int lb,int ub)
{
    var *val1,*val2;
    val1=(var *)malloc(sizeof(var));
    val2=(var *)malloc(sizeof(var));
    if(lb-ub==0)
        {
            val1->max=ar[lb];
            val1->min=ar[lb];
            return val1;
        }
    else if(lb-ub==-1)
    {
        if(ar[lb]>ar[ub])
        {
            val1->max=ar[lb];
            val1->min=ar[ub];
        }
        else
        {
             val1->max=ar[ub];
            val1->min=ar[lb];
        }
        return val1;
    }
    else
    {
        val1=minmax(ar,lb,((lb+ub)/2));
        val2=minmax(ar,((lb+ub)/2)+1,ub);
        if(val1->max < val2->max)
            val1->max=val2->max;
        if(val1->min > val2->min)
            val1->min=val2->min;
        return val1;
    }
}
int main()
{
    int n,*ar,i;
    var *c=(var *)malloc(sizeof(var));
    printf("Enter the no of elements you want in the array\n");
    scanf("%d",&n);
    ar =(int *)malloc(n*sizeof(int));
    printf("Enter the array elements you want in the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    st=time(NULL);
    c=minmax(ar,0,n-1);
    printf("Max element %d and min element is %d",c->max,c->min);
    getch();
}
