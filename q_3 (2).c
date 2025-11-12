// Program to implement a circular queue
#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

int empty() { return front == -1; }
int full()  { return front == (rear + 1) % SIZE; }

void enq(int v) {
    if (full()) { printf("full\n"); return; }
    if (empty()) front = rear = 0; else rear = (rear + 1) % SIZE;
    q[rear] = v; printf("enq %d\n", v);
}

int deq() {
    if (empty()) { printf("empty\n"); return -1; }
    int v = q[front];
    if (front == rear) front = rear = -1; else front = (front + 1) % SIZE;
    printf("deq %d\n", v);
    return v;
}

void disp() {
    if (empty()) { printf("[]\n"); return; }
    printf("[");
    for (int i = front; ; i = (i + 1) % SIZE) {
        printf("%d", q[i]);
        if (i == rear) break;
        printf(" ");
    }
    printf("]\n");
}

int main(void) {
    int vals[] = {10, 20, 30, 40, 50}; 
    for (int i = 0; i < 4; ++i) enq(vals[i]); 
    disp();
    deq(); deq();
    disp();
    enq(vals[4]); enq(60); 
    disp();
    enq(70); 
    while (!empty()) deq();
    disp();
    return 0;
}