#include<stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue [rear] = x;
    }
    else if ((rear+1)%N == front)
    {
        printf("Queue is full, cannot enter more elements.");
    }
    else
    {
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty, nothing to delete.");
    }
    else if (front == rear)
    {
        printf("Dequeued= %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued= %d\n", queue[front]);
        front = (front +1)%N;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty, nothing to display.\n");
    }
    else
    {
        printf("Queue elements: ");
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        else
        {
            for (int i = front; i < N; i++)
                printf("%d ", queue[i]);
            for (int i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


int main()
{
    int choice, value;
    while(1)
    {
        printf("\nQueue Menu\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit the program\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the value to insert:");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("You have exited the program.\nBye!\n");
            return 0;
        default:
            printf("Invalid choice! Please select between 1 and 4\n");
        }
    }
}
