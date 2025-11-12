// Program to implement a double-ended queue(Deque)
#include <stdio.h>
#define SIZE 5

int d[SIZE], front = -1, rear = -1;

int empty() { return front == -1; }
int full()  { return front == (rear + 1) % SIZE; }

void insRear(int v) {
    if (full()) { printf("full\n"); return; }
    if (empty()) front = rear = 0; else rear = (rear + 1) % SIZE;
    d[rear] = v; printf("insR %d\n", v);
}

void insFront(int v) {
    if (full()) { printf("full\n"); return; }
    if (empty()) front = rear = 0; else front = (front - 1 + SIZE) % SIZE;
    d[front] = v; printf("insF %d\n", v);
}

int delFront() {
    if (empty()) { printf("empty\n"); return -1; }
    int v = d[front];
    if (front == rear) front = rear = -1; else front = (front + 1) % SIZE;
    printf("delF %d\n", v); return v;
}

int delRear() {
    if (empty()) { printf("empty\n"); return -1; }
    int v = d[rear];
    if (front == rear) front = rear = -1; else rear = (rear - 1 + SIZE) % SIZE;
    printf("delR %d\n", v); return v;
}

void disp() {
    if (empty()) { printf("[]\n"); return; }
    printf("[");
    for (int i = front; ; i = (i + 1) % SIZE) {
        printf("%d", d[i]);
        if (i == rear) break;
        printf(" ");
    }
    printf("]\n");
}

int main(void) {
    int vals[] = {10, 20, 30, 40, 50}; 
    insRear(vals[0]); insRear(vals[1]); insRear(vals[2]); 
    insFront(5);               
    insRear(vals[3]);          
    disp();
    delFront(); delFront(); delRear(); 
    disp();
    insFront(vals[4]); insRear(60); 
    disp();
    insRear(70); 
    while (!empty()) delFront();
    disp();
    return 0;
}