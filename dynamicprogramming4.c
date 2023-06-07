Problem Description
There are two strings src and dest. The goal of the problem is to convert src to dest by applying minimum edit operations on string str1. The edit operations are following –

1) insert a character
2) delete a character
3) replace a character

Problem Solution
This problem can be solved optimally using bottom up DP. We will first calculate minimum operations required to transform a prefix of the string src to a prefix of string dest. Then we will use this information to calculate minimum no. of operations required to transform a bigger prefix of src to a bigger prefix of dest.

The time complexity of this solution will be O(len1*len2).

Expected Input and Output
Case-1:
str1="vish"
str2="vishal"
 
Minimum number of edit operations=2
inserting 2 chracters 'a' and 'l'
Case-2:

str1="vshkl"
str2="vishal"
 
Minimum number of edit operations=2
inserting 'i' and replacing 'k' with 'a'
Case-3:
str1="apiskal"
str2="vishal"
 
Minimum number of edit operations=3
deleting 'a', replacing 'p' with 'v' and replacing 'k' with 'h'

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int num1,int num2)
{
    int minimum;
    if(num1<=num2)
    {
        minimum = num1;
    }
    else
    {
        minimum = num2;
    }
    return minimum;
}

int editdistance(char *str1,char *str2)
{
    int len1,len2,i,j;
    for(len1=0;str1[len1]!='\0';len1++);
    for(len2=0;str2[len2]!='\0';len2++);
    int edit[len1+1][len2+1];
    for(i=0;i<=len1;i++)
    {
        edit[i][0] = i;
    }
    for(j=0;j<=len2;j++)
    {
        edit[0][j] = j;
    }
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                edit[i][j] = edit[i-1][j-1];
            }
            else
            {
                int x = 1+edit[i-1][j];
                int y = 1+edit[i][j-1];
                int z = 1+edit[i-1][j-1];
                
                edit[i][j] = min(x,min(y,z));
            }
        }
    }
    return edit[len1][len2];
}

int main()
{
    char str1[100];
    char str2[100];
    scanf("%s",str1);
    scanf("%s",str2);
    int distance = editdistance(str1,str2);
    printf("%d ",distance);
    return 0;
}
