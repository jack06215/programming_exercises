#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to visit nodes in Preorder
void Preorder(struct Node* root) {
    // base condition for recursion
    // if tree/sub-tree is empty, return and exit
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);     // Visit left subtree
    Preorder(root->right);    // Visit right subtree
}

// Function to visit nodes in Inorder
void Inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    Inorder(root->left);       //Visit left subtree
    cout << root->data << " ";
    Inorder(root->right);      // Visit right subtree
}

// Function to visit nodes in Postorder
void Postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    Postorder(root->left);    // Visit left subtree
    Postorder(root->right);   // Visit right subtree
    cout << root->data << " ";
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node();
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

int main() {
    /*
                1
               / \
              2   3
             / \   \
            4   5   6
    */
    Node* root = nullptr;
    root = Insert(root, 1);
    root = Insert(root, 2);
    root = Insert(root, NULL);
    root = Insert(root, 4);
    root = Insert(root, 5);
    root = Insert(root, 6);
    //Print Nodes in Preorder. 
    cout << "Preorder: ";
    Preorder(root);
    cout << "\n";
    cout << (nullptr == 0) << endl;
    //Print Nodes in Inorder
    cout << "Inorder: ";
    Inorder(root);
    cout << "\n";
    //Print Nodes in Postorder
    cout << "Postorder: ";
    Postorder(root);
    cout << "\n";
}