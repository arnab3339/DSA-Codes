#include<iostream>
#include<stdlib.h>

using namespace std;

#define max 10

int queue[max];
int rear = -1;
int front = -1;

void enqueue() {
    int val;
    if (rear >= max - 1)
        cout << "Overflow" << endl;
    else {
        if (front == -1) {
            front = 0;
        }
        cout << "Enter the value : ";
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        cout << "Underflow" << endl;
    else {
        cout << "Deleted element: " << queue[front] << endl;
        front++;
    }
}

void display() {
    int i;
    if (front == -1 || front > rear)
        cout << "Queue is empty" << endl;
    else {
        cout << "Queue Element : ";
        for (i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int ch;
    do {
        cout << endl;
        cout << "1 EnQueue" << endl;
        cout << "2 DeQueue" << endl;
        cout << "3 Display" << endl;
        cout << "4 Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }
    } while (ch != 4);
    return 0;
}
