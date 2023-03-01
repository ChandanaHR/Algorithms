//COLLISSION RESOLVING USING DOUBLE HASHING IN HASHING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

int n;

int isprime(int m)
{
    if(m<=1)
    {
        return false;
    }
    for(int i=2;i<=sqrt(m);i++)
    {
        if(m%i == 0)
        {
            return false;
        }
    }
    return true;
}

int nearestprime(int n)
{
    int prime = 0;
    for(int i=n-1;i>=2;i--)
    {
        if(isprime(i))
        {
           prime = i;
           break;
        }
    }
}

void insert(int p,int *arr)
{
    int value,key,index,hash,i;
    printf("Enter the value to be inserted\n");
    scanf("%d",&value);
    key = value%n;
    hash = p-(value%p);
    for(i=0;i<n;i++)
    {
        index = (key+i*hash)%n;
        if(arr[index] == -1)
        {
            arr[index] = value;
            break;
        }
    }
    if(i==n)
    {
        printf("Element cannot be inserted\n");
    }
}

void search(int p,int *arr)
{
    int value,key,index,hash,i,flag=0,found;
    printf("Enter the value to be searched\n");
    scanf("%d",&value);
    key = value%n;
    hash = p-(value%p);
    for(i=0;i<n;i++)
    {
        index = (key+i*hash)%n;
        if(arr[index] == value)
        {
            flag=1;
            found = index;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element found at index: %d",found);
    }
    else
    {
        printf("Element not found:\n");
    }
}

void delete(int p,int *arr)
{
    int value,key,index,hash,i,flag=0,found;
    printf("Enter the value to be deleted\n");
    scanf("%d",&value);
    key = value%n;
    hash = p-(value%p);
    for(i=0;i<n;i++)
    {
        index = (key+i*hash)%n;
        if(arr[index] == value)
        {
            arr[index] = -1;
            flag=1;
            found = index;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element deleted at index: %d",found);
    }
    else
    {
        printf("Element not found:\n");
    }
}

void display(int *arr)
{
    printf("Elements of the array\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    printf("-----DOUBLE HASHING COLLISSION RESOLUTION-----\n");
    printf("1. Insert an element in array\n");
    printf("2. Search an element in array\n");
    printf("3. Delete an element in array\n");
    printf("4. Display an array elements\n");
    printf("5. Exit\n");
    int p,choice;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        arr[i] = -1;
    }
    p = nearestprime(n);
    printf("%d",p);
    while(1)
    {
        printf("\n\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(p,arr);
                    break;
            case 2: search(p,arr);
                    break;
            case 3: delete(p,arr);
                    break;
            case 4: display(arr);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
