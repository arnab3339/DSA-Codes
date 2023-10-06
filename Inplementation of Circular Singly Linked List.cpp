#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Circular linked list, point to itself
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL && current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}


Node* insertAtIndex(Node* head, int data, int index) {
    if (index < 0) {
        cout << "Invalid Index";
        return head;
    }
    if (index == 0)
        return insertAtBeginning(head, data);
    
    Node* newNode = createNode(data);
    Node* current = head;
    int currentIndex = 0;
    while (current != NULL && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }
    if (current == NULL) {
        cout << "Invalid Index";
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        cout << "List is Empty" << endl;
        return NULL;
    }
    if (head->next == head) { // Only one element in the list
        delete head;
        return NULL;
    }
    Node* temp = head->next;
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = temp;
    delete head;
    return temp;
}

Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        cout << "List is Empty" << endl;
        return NULL;
    }
    if (head->next == head) { // Only one element in the list
        delete head;
        return NULL;
    }
    Node* current = head;
    Node* prev = NULL;
    while (current->next != head) {
        prev = current;
        current = current->next;
    }
    prev->next = head;
    delete current;
    return head;
}

int main() {
    Node* head = NULL;
    int choice, data, index;
    do {
        cout << "\n===========================================\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Index\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "6. Delete at Beginning\n";
        cout << "7. Delete at End\n";
        cout << "\n===========================================\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Data: ";
                cin >> data;
                head = insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter Data: ";
                cin >> data;
                head = insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter Data: ";
                cin >> data;
                cout << "Enter Index: ";
                cin >> index;
                head = insertAtIndex(head, data, index);
                break;
            case 4:
                cout << "Linked List: ";
                display(head);
                break;
            case 5:
                cout << "End";
                break;
            case 6:
                head = deleteAtBeginning(head);
                break;
            case 7:
                head = deleteAtEnd(head);
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while (choice != 5);
    return 0;
}
