#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        cout << "Pushed item: " << item << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop item." << endl;
            return;
        }
        int item = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped item: " << item << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements:" << endl;
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};
int main() {
    Stack stack;
    int choice, item;
    do {
        cout << "Select an operation:" << endl;
        cout << "1) Push to Stack" << endl;
        cout << "2) Pop from Stack" << endl;
        cout << "3) Display Stack" << endl;
        cout << "4) Exit" << endl;
        cout << "Enter your Choice: ";
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
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid Choice. Try Again." << endl;
                break;
        }
    } while (choice != 4);
    return 0;
}
