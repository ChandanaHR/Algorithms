Subset Sum Problem using Dynamic Programming
Problem Description
There is a subset A of n positive integers and a value sum. Find whether or not there exists any subset of the given set, the sum of whose elements is equal to the given value of sum.
 Expected Input and Output
Case-1:

sum=17
n=4
A[]={2,4,6,9}
 
Required subset exists
subset {2,6,9} has the sum 17

  Case-2:

sum=17
n=4
A[]={2,4,6,8}
 
No Subset found with required sum

#include<stdio.h>
#include<stdlib.h>

int subsetsum(int n,int arr[],int sum)
{
    int dp[n+1][sum+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }
    for(j=0;j<=sum;j++)
    {
        dp[0][sum] = 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(dp[i-1][j]==1)
            {
                dp[i][j] = 1;
            }
            else
            {
                if(arr[i-1]>j)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]];
                }
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return dp[n][sum];
}

int main()
{
    int n,sum;
    scanf("%d %d",&n,&sum);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int a = subsetsum(n,arr,sum);
    if(a==1)
    {
        printf("subset with given sum exists\n");
    }
    else
    {
        printf("subset with given sum doesn't exists\n");
    }
    return 0;
}
