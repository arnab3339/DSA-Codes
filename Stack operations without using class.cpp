#include <iostream>
#include <stdlib.h>
using namespace std;

#define max 5
int stack[max], top = -1;

void push(int value) {
    if (top >= max - 1) {
        cout << "Stack Overflow";
    } else {
        top = top + 1;
        stack[top] = value;
    }
}

void pop() {
    if (top <= -1) {
        cout << "Stack Underflow";
    } else {
        cout << "Popped element: " << stack[top];
        top = top - 1;
    }
}

void display() {
    int i;
    if (top >= 0) {
        cout << "Stack elements are: ";
        for (i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
    } else {
        cout << "Stack is Empty";
    }
}

int main() {
    int ch, value;
    do {
        cout << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Wrong Choice";
        }
    } while (ch != 4);
    return 0;
}
