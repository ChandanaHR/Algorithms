// HASHING: COLLISSION AVOIDANCE USING LINEAR PROBING

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;

void create(int *arr)
{
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        arr[i] = -1;
    }
}

void insert(int *arr)
{
    int value,key,index,i;
    printf("Enter the value to be inserted\n");
    scanf("%d",&value);
    key = value%n;
    for(int i=0;i<n;i++)
    {
        index = (key+i)%n;
        if(arr[index]==-1)
        {
            arr[index] = value;
            break;
        }
        if(i==n)
        {
            printf("Element cant be inserted\n");
        }
    }
}

void search(int *arr)
{
    int value,key,index,i,flag=0,found;
    printf("Enter the value to be searched\n");
    scanf("%d",&value);
    key = value%n;
    for(int i=0;i<n;i++)
    {
        index = (key+i)%n;
        if(arr[index]==value)
        {
            found=index;
            flag=1;
            break;
        }
        if(i==n)
        {
            printf("Element is not found\n");
        }
    }
    if(flag==1)
    {
        printf("Element is found at index: %d",found);
    }
    else
    {
        printf("Element is not found\n");
    }
}

void display(int *arr)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void delete(int *arr)
{
    int value,key,index,i,flag=0;
    printf("Enter the value to be inserted\n");
    scanf("%d",&value);
    key = value%n;
    for(int i=0;i<n;i++)
    {
        index = (key+i)%n;
        if(arr[index]==value)
        {
            flag=1;
            arr[index] = -1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element has been deleted: %d",index);
    }
    else
    {
        printf("Element is not found\n");
    }
}

int main()
{
    int *arr = (int *)malloc(n*sizeof(int));
    int choice;
    printf("---HASHING OPERATIONS USING LINEAR PROBING---\n");
    printf("1. Create an array\n");
    printf("2. Insert an element in array\n");
    printf("3. Display an array\n");
    printf("4. Search an element in array\n");
    printf("5. Delete an element from array\n");
    printf("6. Exit\n");
    while(1)
    {
        printf("\n\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create(arr);
                    break;
            case 2: insert(arr);
                    break;
            case 3: display(arr);
                    break;
            case 4: search(arr);
                    break;
            case 5: delete(arr);
                    break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
