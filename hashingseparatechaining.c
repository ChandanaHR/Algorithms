//HASHING USING OPEN HASHING OR SEPARATE CHAINING WITHOUT COLLISSION USING ARRAY OF LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert(struct node **chain,int n)
{
    int value;
    printf("Enter the value\n");
    scanf("%d",&value);
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;

    int key = value % n;

    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        struct node *temp = chain[key];
        while(temp->link)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
}

void search(struct node **chain,int n)
{
    int value,flag=0;
    printf("Enter the value to be searched\n");
    scanf("%d",&value);
    int key = value%n;
    struct node *temp = chain[key];
    while(temp)
    {
        if(temp->data == value)
        {
            flag = 1;
        }
        temp = temp->link;
    }
    if(flag == 1)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}

void removing(struct node **chain,int n)
{
    int value,key;
    printf("Enter the value to be deleted\n");
    scanf("%d",&value);
    key = value%n;
    struct node *dealloc;
    struct node *temp = chain[key];
    if(temp != NULL)
    {
        if(temp->data == value)
        {
            dealloc = temp;
            temp = temp->link;
            free(dealloc);
        }
        else
        {
            while(temp->link)
            {
                if(temp->link->data == value)
                {
                    dealloc = temp->link;
                    temp->link = temp->link->link;
                    free(dealloc);
                }
                temp = temp->link;
            }
        }
    }
}

void display(struct node **chain,int n)
{
    int i;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    for(i=0;i<n;i++)
    {
        temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of hash chain\n");
    scanf("%d",&n);
    struct node *chain[n];
    for(int i=0;i<n;i++)
    {
       chain[i] = NULL;
     }
    int choice;
    printf("1. Insert an element into hash chain\n");
    printf("2. Searching an element in hash chain\n");
    printf("3. Removing an element in hash chain\n");
    printf("4. Display contents of hash chain\n");
    printf("5. Exit\n");
    while(1)
    {
        printf("\n\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(chain,n);
                    break;
            case 2: search(chain,n);
                    break;
            case 3: removing(chain,n);
                    break;
            case 4: display(chain,n);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

