#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        return newNode;
    }
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
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
    while (current != nullptr && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }
    if (current == nullptr) {
        cout << "Invalid Index";
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void displayForward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* deleteAtBeginning(Node* head) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return nullptr;
    }
    Node* temp = head->next;
    delete head;
    return temp;
}

Node* deleteAtEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return head;
}

int main() {
    Node* head = nullptr;
    int choice, data, index;
    do {
        cout << "\n===========================================\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Index\n";
        cout << "4. Display Forward\n";
        cout << "5. Delete at Beginning\n";
        cout << "6. Delete at End\n";
        cout << "7. Exit\n";
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
                cout << "Singly Linked List (Forward): ";
                displayForward(head);
                break;
            case 5:
                head = deleteAtBeginning(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                cout << "Exiting Program....\n";
                break;
            default:
                cout << "Invalid Choice!!\n";
        }
    } while (choice != 7);
    return 0;
}
