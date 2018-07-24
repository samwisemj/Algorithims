#include <stdio.h>
#include <stdlib.h>
void main()
{
    double **ar,temp,n,rwt,kwt,twt,benifit;
    int i,j;
    printf("\nEnter the no of items : ");
    scanf("%lf",&n);
    ar=(double **)malloc(n*sizeof(double *));
    for(i=0;i<4;i++)
        ar[i]=(double *)malloc(n*sizeof(double));
    printf("\nEnter wt and profit for items\n");
    for(i=0;i<n;i++)
    {
        ar[0][i]=i+1;
        printf("Item %d :",i+1);
        scanf("%lf %lf",&ar[1][i],&ar[2][i]);
        ar[3][i]=ar[2][i]/ar[1][i];
    }
    for (i=0;i<(n-1);i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (ar[3][j] < ar[3][j+1])
            {
            temp=ar[3][j];  ar[3][j]=ar[3][j+1];    ar[3][j+1] = temp;
            temp=ar[2][j];  ar[2][j]=ar[2][j+1];    ar[2][j+1] = temp;
            temp=ar[1][j];  ar[1][j]=ar[1][j+1];    ar[1][j+1] = temp;
            temp=ar[0][j];  ar[0][j]=ar[0][j+1];    ar[0][j+1] = temp;
            }
        }
    }
    printf("Enter total wt of knapsack\n");
    scanf("%lf",&kwt);
    benifit=0.0,twt=0.0,i=0;
    printf("The solution to the knapsack is\n");
    while(twt<kwt)
    {
        if(ar[1][i]+twt<=kwt)
        {
            printf("\nItem %.0lf : Full",ar[0][i]);
            twt+=ar[1][i];
            benifit+=ar[2][i];
        }
        else
        {
            rwt=kwt-twt;
            printf("\nItem %.0lf : %.2lf",ar[0][i],rwt);
            twt+=rwt;
            benifit+=rwt*ar[3][i];
        }
        i++;
    }
    printf("\nBenifit from knapsack is %.3lf",benifit);
    printf("\nTotal weight in knapsack is %.3lf",twt);
}
