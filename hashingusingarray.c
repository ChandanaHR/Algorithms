//HASHING OPERATIONS USING ARRAY WITH COLLISSION

#include<stdio.h>
#include<stdlib.h>

int n;


void create(int *arr)
{
    int i;
    printf("Enter the size of hash bucket\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        arr[i] = -1;
    }
}

void insert(int *arr)
{
    int value,key;
    printf("Enter the value to be inserted\n");
    scanf("%d",&value);
    key = value%n;
    if(arr[key]==-1)
    {
        arr[key] = value;
    }
    else
    {
        printf("Warning-----Unable to insert\n");
        printf("Collission at an index %d with element %d: \n",key,arr[key]);
    }
}

void search(int *arr)
{
    int value,key;
    printf("Enter the value to be inserted\n");
    scanf("%d",&value);
    key = value%n;
    if(arr[key] == value)
    {
        printf("Element to be searched is found\n");
    }
    else
    {
        printf("Element to be searched is not found\n");
    }
}

void delete(int *arr)
{
    int value,key;
    printf("Enter the value to be deleted\n");
    scanf("%d",&value);
    key = value%n;
    if(arr[key]==value)
    {
        arr[key] = -1;
    }
    else
    {
        printf("%d Element is not present in hash table:\n",value);
    }
}

void display(int *arr)
{
    printf("Elements of hash bucket\n");
    for(int i=0;i<n;i++)
    {
        printf("%d \n",arr[i]);
    }
}

int main()
{
    int *arr = (int *)malloc(n*sizeof(int));
    int choice;
    printf("-----HASHING OPERATIONS USING ARRAY-------\n");
    printf("1. Create an hash bucket\n");
    printf("2. Insert an element in hash bucket\n");
    printf("3. Search an element in hash bucket\n");
    printf("4. Delete an element in hash bucket\n");
    printf("5. Display an hash bucket\n");
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
            case 3: search(arr);
                    break;
            case 4: delete(arr);
                    break;
            case 5: display(arr);
                    break;
            case 6: exit(0);
            default: printf("Invalid\n");
        }
    }
}

