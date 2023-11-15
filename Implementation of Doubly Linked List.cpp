#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
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
    newNode->prev = current;
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
    newNode->prev = current;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
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

void displayBackward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

Node* deleteAtBeginning(Node* head) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return nullptr;
    }
    Node* temp = head->next;
    if (temp != nullptr) {
        temp->prev = nullptr;
    }
    delete head;
    return temp;
}

Node* deleteAtEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return nullptr;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    if (current->prev != nullptr) {
        current->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete current;
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
        cout << "5. Display Backward\n";
        cout << "6. Exit\n";
        cout << "7. Delete at Beginning\n";
        cout << "8. Delete at End\n";
        cout<<"9. Exit\n";
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
                cout << "Doubly Linked List (Forward): ";
                displayForward(head);
                break;
            case 5:
                cout << "Doubly Linked List (Backward): ";
                displayBackward(head);
                break;
            case 6:
                cout << "End";
                break;
            case 7:
                head = deleteAtBeginning(head);
                break;
            case 8:
                head = deleteAtEnd(head);
                break;
            case 9:
                cout <<"Exiting Program....\n";
            
        }
    } while (choice != 6);
    return 0;
}
