//LONGEST INCREASING SUBSEQUENCE
Given a sequence of n real numbers A(1) … A(n), determine a subsequence (not necessarily contiguous) of maximum length in which the values in the subsequence form a strictly increasing sequence.
Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6

  
Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
  
#include<stdio.h>
#include<stdlib.h>

int longestincreasingsubsequence(int n,int *arr)
{
    int *length = (int *)malloc(n*sizeof(int));
    int max = 0;
    for(int i=0;i<n;i++)
    {
        length[i] = 1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && length[j]+1>length[i])
            {
                length[i] = length[j]+1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(length[i]>max)
        {
            max = length[i];
        }
    }
    return max;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int l = longestincreasingsubsequence(n,arr);
    printf("%d",l);
    return 0;
}
