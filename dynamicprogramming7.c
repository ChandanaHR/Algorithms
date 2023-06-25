//PARTITION EQUAL SUBSET SUM PROBLEM
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int partitionequalsubsetsum(int n,int arr[])
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum = sum+arr[i];
    }
    int sum1 = sum/2;
    int dp[n+1][sum1+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }
    for(int j=0;j<=sum1;j++)
    {
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum1;j++)
        {
            if(arr[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum1;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return dp[n][sum1];
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int a = partitionequalsubsetsum(n,arr);
    if(a==1)
    {
        printf("Partition subset is possible for given array\n");
    }
    else
    {
        printf("Partition subset is not possible for given array\n");
    }
    return 0;
}
