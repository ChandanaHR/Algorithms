Find nth fibonacci number

The Fibonacci Sequence is the series of numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, …
The next number is found by adding up the two numbers before it.

Let F[i] be the ith fibonacci number

F[0]=0
F[1]=1

F[i]=F[i-1]+F[i-2]
Expected Input and Output
Case-1:

 
n=3
Expected result=2
Case-2:
n=4
Expected result=3
Case-3:

 
n=5
Expected result=5

#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n)
{
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=n;i++)
    {
        fib[i] = fib[i-1]+fib[i-2];
    }
    return fib[n];
}

int main()
{
    int n;
    scanf("%d",&n);
    int a = fibonacci(n);
    printf("%d\n",a);
    return 0;
}
