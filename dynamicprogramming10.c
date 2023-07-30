//STOCK BUY AND SELL
The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on which you buy and sell the stock so that in between those days for which profit can be generated.
Note: Since there can be multiple solutions, the driver code will print 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will print the string "No Profit" for a correct solution.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will 
give us maximum profit. Now, we buy 
stock on day 4 and sell it on day 6.
Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
1
Explanation:
There are multiple possible solutions.
one of them is (3 4)
We can buy stock on day 3,
and sell it on 4th day, which will 
give us maximum profit.

  #include<stdio.h>
#include<stdlib.h>

int stockbuyandsell(int n,int *prices)
{
    int maxprofit = 0,buy,sell,count=0;
    for(int i=1;i<n;i++)
    {
        if(prices[i]>prices[i-1])
        {
            count++;
            buy = i-count;
            sell = i;
            maxprofit+=prices[i]-prices[i-1];
        }
        else
        {
            count = 0;
        }
        printf("Buy: %d sell: %d \n",buy,sell);
    }
    return maxprofit;
}

int main()
{
    int n;
    scanf("%d",&n);
    int prices[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&prices[i]);
    }
    int a = stockbuyandsell(n,prices);
    printf("%d",a);
    return 0;
}
