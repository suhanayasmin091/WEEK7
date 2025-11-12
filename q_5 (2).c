// Program to implement a priority queue
#include <stdio.h>
#define SIZE 10

struct item {
    int data;
    int priority;
};

struct item pq[SIZE];
int n = 0;

void insert(int data, int priority) {
    if (n == SIZE) {
        printf("Queue Overflow\n");
        return;
    }
    pq[n].data = data;
    pq[n].priority = priority;
    n++;
}

int getHighestPriorityIndex() {
    int i, hp = 0;
    for (i = 1; i < n; i++) {
        if (pq[i].priority > pq[hp].priority)
            hp = i;
    }
    return hp;
}

void delete() {
    if (n == 0) {
        printf("Queue Underflow\n");
        return;
    }
    int i, hp = getHighestPriorityIndex();
    printf("Deleted item: %d (priority %d)\n", pq[hp].data, pq[hp].priority);
    for (i = hp; i < n - 1; i++)
        pq[i] = pq[i + 1];
    n--;
}

void display() {
    if (n == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Priority Queue:\n");
    for (int i = 0; i < n; i++)
        printf("Data: %d  Priority: %d\n", pq[i].data, pq[i].priority);
}

int main() {
    insert(10, 2);
    insert(30, 3);
    insert(20, 1);
    display();
    delete();
    display();
    return 0;
}
