Coin change Dynamic programming approach
Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin. 


Example 1:

Input:
sum = 4 , 
N = 3
coins[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
Sum = 10 , 
N = 4
coins[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int coinchange(int n,int *arr,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }
    for(int j=1;j<=sum;j++)
    {
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] =  dp[i-1][j]+dp[i][j-arr[i-1]];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
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
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int a = coinchange(n,arr,sum);
    printf("%d\n",a);
    return 0;
}
