// Program to check overflow and underflow conditions in a queue
#include <stdio.h>

#define SIZE 4

int queue[SIZE];
int front = -1, rear = -1;

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; ++i)
        printf("%d ", queue[i]);
    printf("\n");
}

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Enqueue %d -> Queue Overflow\n", value);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Enqueued: %d\n", value);
    display();
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Dequeue -> Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front++]);
    if (front > rear) front = rear = -1; 
    display();
}

int main(void) {
    int values[] = {10, 20, 30, 40, 50};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i) {
        enqueue(values[i]);
    }

    for (int i = 0; i < n; ++i) {
        dequeue();
    }
    return 0;
}