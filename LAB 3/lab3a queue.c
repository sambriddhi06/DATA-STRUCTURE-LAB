#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enque(int x)
{
    if (rear == N - 1)
    {
        printf("Queue Overflow (The Queue is full, cannot enter more elements)\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void deque()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty, nothing to delete\n");
    }
    else if (front == rear)
    {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
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
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nQueue Menu\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            enque(value);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("You have exited the program.\nBye!\n");
            return 0;
        default:
            printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
}
