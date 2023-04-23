//KADANES ALGORITHM TO FIND SUM OF MAXIMUM CONTIGUOUS ARRAY
//Brute force solution
#include<stdio.h>
#include<stdlib.h>

int brute(int n,int *arr)
{
    int i,j,overallsum=0,newsum;
    for(i=0;i<n;i++)
    {
        newsum = 0;
        for(j=i;j<n;j++)
        {
            newsum+=arr[j];
            if(newsum > overallsum)
            {
                overallsum = newsum;
            }
        }
    }
    return overallsum;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum = brute(n,arr);
    printf("%d",sum);
    return 0;
}

//Dynamic programming solution
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
    int maximum=0;
    if(a>=b)
    {
        maximum = a;
    }
    else
    {
        maximum = b;
    }
    return maximum;
}

int dp(int n,int *arr)
{
    int i,overallsum=0,newsum=0;
    for(i=0;i<n;i++)
    {
        newsum = max(arr[i],newsum+arr[i]);
        overallsum = max(overallsum,newsum);
    }
    return overallsum;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum = dp(n,arr);
    printf("%d",sum);
    return 0;
}
