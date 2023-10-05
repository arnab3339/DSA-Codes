#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
Node *createNode(int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
	
}
Node *insertAtBeginning(Node *head, int data){
	Node *newNode = createNode(data);
	newNode->next = head;
	return newNode;
}
Node *insertAtEnd(Node *head,int data){
	Node *newNode = createNode(data);
	newNode->next = head;
	if(head == NULL)
		return newNode;
		Node *current = head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
		return head;
}
Node *insertAtIndex(Node *head, int data, int index){
	if(index<0){
		cout<<"Invalid Index";
		return head;
	}
	if(index == 0)
		return insertAtBeginning(head, data);
		Node *newNode = createNode(data);
		Node *current = head;
		int currentIndex = 0;
		while(current != NULL && currentIndex <index-1){
			current = current->next;
			currentIndex;
		}
		if(current == NULL){
			cout<<"Invalid";
			return head;
		}
		newNode->next = current->next;
		current->next = newNode;
		return head;
}
void display(Node *head){
	Node *current = head;
	cout<<current->data<<" ";
	current = current->next;
	while(current->next != head){
		cout<<current->data<<" ";
		current = current->next;
	}
	cout<<current->data<<" ";
}
		Node *deleteatbeginning(Node *head){
			if(head == NULL){
				cout<<"List Empty";
				return NULL;
			}
			Node *temp = head->next;
			Node *current = temp;
			while(current != head){
				current = current->next;
			}
			current->next = temp;
			delete head;
			return temp;
		}
		Node *deleteatend(Node *head){
			if(head == NULL){
				cout<<"List is Empty";
				return NULL;
			}
			if(head->next == NULL){
				delete head;
				return NULL;
			}
			Node *current = head;
			while(current->next->next != head){
				current = current->next;
			}
			delete current->next;
			current->next = head;
			return head;
		}
int main(){
	Node *head = NULL;
	int choice, data, index;
	do{
		cout<<"\n===========================================\n";
		cout<<"1. Insert at Beginning\n";
		cout<<"2. Insert at End\n";
		cout<<"3. Insert at Index\n";
		cout<<"4. Display\n";
		cout<<"5. Exit\n";
		cout<<"6. Delete at Beginning\n";
		cout<<"7. Delete at End\n";
		cout<<"\n===========================================\n";
		cout<<"Enter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter Data: ";
				cin>>data;
				head = insertAtBeginning(head, data);
				break;
			case 2:
				cout<<"Enter Data: ";
				cin>>data;
				head = insertAtEnd(head, data);
				break;
			case 3:
				cout<<"Enter Data: ";
				cin>>data;
				cout<<"Enter Index: ";
				cin>>index;
				head = insertAtIndex(head, data, index);
				break;
			case 4:
				cout<<"Linked List: ";
				display(head);
				break;
			case 5:
				cout<<"End";
				break;
			case 6:
				head = deleteatbeginning(head);
				break;
			case 7:
				head = deleteatend(head);
				break;
			default:
				cout<<"Invalid Choice\n";
		}
	}
	while(choice != 5);
	return 0;
}
