#include <iostream>

// Node structure for the binary search tree
struct Node
{
     int key;
     Node *left;
     Node *right;

     // Constructor
     Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to insert a key into the binary search tree
Node *insert(Node *root, int key)
{
     // If the tree is empty, create a new node as the root
     if (root == nullptr)
     {
          return new Node(key);
     }

     // Otherwise, recur down the tree
     if (key < root->key)
     {
          // Insert into the left subtree
          root->left = insert(root->left, key);
     }
     else if (key > root->key)
     {
          // Insert into the right subtree
          root->right = insert(root->right, key);
     }

     // Return the unchanged node pointer
     return root;
}

// Function to perform an in-order traversal of the binary search tree
void inOrderTraversal(Node *root)
{
     if (root != nullptr)
     {
          inOrderTraversal(root->left);
          std::cout << root->key << " ";
          inOrderTraversal(root->right);
     }
}

int main()
{
     // Create an empty root
     Node *root = nullptr;

     // Insert the key values into the binary search tree
     root = insert(root, 12);
     root = insert(root, 8);
     root = insert(root, 23);
     root = insert(root, 9);
     root = insert(root, 14);
     root = insert(root, 15);

     // Perform in-order traversal to print the sorted keys
     std::cout << "In-order traversal of the binary search tree: ";
     inOrderTraversal(root);
     std::cout << std::endl;

     return 0;
}
