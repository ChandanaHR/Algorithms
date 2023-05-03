// 0/1 KNAPSACK PROBLEM USING DYNAMIC PROGRAMMING APPROACH
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
    int max;
    if(a>=b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    return max;
}

int knapsack(int n,int *weight,int *value,int c)
{
    int i,j;
    int knap[n+1][c+1];
    for(i=0;i<=c;i++)
    {
        knap[0][i] = 0;
    }
    for(j=0;j<=n;j++)
    {
        knap[j][0] = 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(weight[i-1]<=j)
            {
                knap[i][j] = max(knap[i-1][j],knap[i-1][j-weight[i-1]]+value[i-1]);
            }
            else
            {
                knap[i][j] = knap[i-1][j];
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            printf("%d ",knap[i][j]);
        }
        printf("\n");
    }
    return knap[n][c];
}

int main()
{
    int n,i,c;
    scanf("%d",&n);
    printf("Enter the capacity of the knapsack\n");
    scanf("%d",&c);
    int *weight = (int *)malloc(n*sizeof(int));
    int *value = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&value[i]);
    }
    printf("Weights of the items are\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",weight[i]);
    }
    printf("\n");
    printf("Profits of the items are\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",value[i]);
    }
    printf("\n");
    int k = knapsack(n,weight,value,c);
    printf("%d\n",k);
    return 0;
}
