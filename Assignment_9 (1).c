#include <stdio.h>
#include <string.h>

struct job
{
    int jobID;
    char name[50];
};

int length = 5;
struct job j[5];
int rear = 0;
int front = 0;



void add(struct job j[5], char name[50], int id)
{
    if ((rear + 1)% length == front)
    {
        printf("Queue is full\n\n");
    }
    else
    {
        rear = (rear + 1)% length;
        strcpy(j[rear].name , name);
        j[rear].jobID = id;        
    }
}

void processjob()
{
    if (front == rear)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        front = (front + 1) % length;
        printf("\nDeleted item is : ID = %d name = %s\n",
               j[front].jobID,
               j[front].name);
    }
}

void display()
{
    if (front == rear)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nCurrent jobs in the queue:\n");
        int i = (front + 1) % length;
        while (i != (rear + 1) % length)
        {
            printf("ID = %d, Name = %s\n", j[i].jobID, j[i].name);
            i = (i + 1) % length;
        }
    }
}

int main()
{
    int n;
    char name1[50];
    int cont = 1;
    int JobID;

    do
    {
        printf("\nEnter your choice : 1) AddingJob 2) Processing job 3) Display jobs 4) Exit\n :");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
            {
                printf("Enter the name: ");
                
                scanf("%s", name1);

                printf("Enter the jobID :");
                scanf("%d", &JobID); 
                add(j, name1 , JobID);
            }
            break;

            case 2:
                processjob();
                break;

            case 3:
                display();
                break;

            case 4:
                cont = 0;
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    while (cont == 1);

    return 0;
}