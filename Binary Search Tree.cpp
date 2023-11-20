#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = nullptr;
    }
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
            if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }
        return root;
    }
    void preorderTraversal(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
    void postorderTraversal(Node* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }
    }
};
int main() {
    BinaryTree bst;
    int choice, value;
    do {
        cout << "\nBinary Search Tree Operations:";
        cout << "\n1. Insert";
        cout << "\n2. Preorder Traversal";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Preorder: ";
                bst.preorderTraversal(bst.root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder: ";
                bst.inorderTraversal(bst.root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder: ";
                bst.postorderTraversal(bst.root);
                cout << endl;
                break;
            case 0:
                cout << "Exiting program.";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.";
        }
} while (choice != 0);
    return 0;
}
