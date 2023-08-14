#include <iostream>
using namespace std;
#define MAX_SIZE 5

class Stack {
    int top;
    int stack[MAX_SIZE];
public:
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == MAX_SIZE - 1);
    }
    void push(int item) {
        if (isFull()) {
            cout << "Stack is full. Cannot push item.\n";
            return;
        }
        stack[++top] = item;
        cout << "Pushed item: " << item << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop item\n";
            return;
        }
        int item = stack[top--];
        cout << "Popped item: " << item << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: \n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, item;
    do {
        cout << "Select an operation:\n";
        cout << "1) Push to Stack\n";
        cout << "2) Pop from Stack\n";
        cout << "3) Display Stack\n";
        cout << "4) Exit\n";
        cout<<"Enter your Choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter item to push: ";
                cin >> item;
                stack.push(item);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid Choice. Try Again.\n";
                break;
        }
    } while (choice != 4);
    return 0;
}
