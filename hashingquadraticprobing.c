// COLLISSION AVOIDANCE USING QUADRATIC PROBING IN HASHING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;

void insert(int *arr)
{
    int index,key,value,i;
    printf("Enter the value to be inserted\n");
    scanf("%d",&value);
    key = value%n;
    for(int i=0;i<n;i++)
    {
        index = (key+i*i)%n;
        if(arr[index]==-1)
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

void search(int *arr)
{
    int index,key,value,i,found,flag=0;
    printf("Enter the value to be searched\n");
    scanf("%d",&value);
    key = value%n;
    for(i=0;i<n;i++)
    {
        index = (key+i*i)%n;
        if(arr[index] == value)
        {
            found = index;
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element found at index: %d ",found);
    }
    else
    {
        printf("Element not found:\n");
    }
}

void delete(int *arr)
{
    int index,key,value,i,flag=0,found;
    printf("Enter the element to be deleted\n");
    scanf("%d",&value);
    key = value%n;
    for(i=0;i<n;i++)
    {
       index = (key+i*i)%n;
       if(arr[index] == value)
       {
           arr[index] = -1;
           flag = 1;
           found = index;
           break;
       }
    }
    if(flag==1)
    {
        printf("Element deleted at index: %d\n",found);
    }
    else
    {
        printf("Element is not found\n");
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
    int choice;
    printf("-----QUADRATIC PROBING COLLISSION AVOIDANCE-----\n");
    printf("1. Insert an element in array\n");
    printf("2. Search an element in array\n");
    printf("3. Delete an element in array\n");
    printf("4. Display array\n");
    printf("5. Exit\n");
    printf("\n");
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        arr[i] = -1;
    }
    while(1)
    {
        printf("\n\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(arr);
                    break;
            case 2: search(arr);
                    break;
            case 3: delete(arr);
                    break;
            case 4: display(arr);
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
