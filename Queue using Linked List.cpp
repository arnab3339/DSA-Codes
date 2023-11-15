#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Enqueued item: " << item << std::endl;
    }
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue item." << std::endl;
            return;
        }
        int item = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        std::cout << "Dequeued item: " << item << std::endl;
    }
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements:" << std::endl;
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};
int main() {
    Queue myQueue;
    int choice, item;
    do {
        std::cout << "Select an operation:" << std::endl;
        std::cout << "1) Enqueue to Queue" << std::endl;
        std::cout << "2) Dequeue from Queue" << std::endl;
        std::cout << "3) Display Queue" << std::endl;
        std::cout << "4) Exit" << std::endl;
        std::cout << "Enter your Choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter item to enqueue: ";
                std::cin >> item;
                myQueue.enqueue(item);
                break;
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                myQueue.display();
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid Choice. Try Again." << std::endl;
                break;
        }
    } while (choice != 4);
    return 0;
}
