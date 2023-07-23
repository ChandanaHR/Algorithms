//LONGEST COMMON SUBSEQUENCE
Given two strings, find the length of longest subsequence present in both of them. Both the strings are in uppercase latin alphabets.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int longestcommonsubsequence(int n1,int n2,char *str1,char *str2)
{
    int dp[n1+1][n2+1];
    int i,j;
    for(i=0;i<=n1;i++)
    {
        dp[i][0] = 0;
    }
    for(j=0;j<=n2;j++)
    {
        dp[0][j] = 0;
    }
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return dp[n1][n2];
}

int main()
{
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    char str1[n1],str2[n2];
    scanf("%s",str1);
    scanf("%s",str2);
    int c = longestcommonsubsequence(n1,n2,str1,str2);
    printf("%d\n",c);
    return 0;
}
