#include <iostream>

using namespace std;

// Creating a tree that has a left and right node and one int

class tree
{
public:
    // The integer value data of the tree
    int data;

    // The left and thr right node of the tree
    tree *left, *right;

    // Constructor that takes a parameter initerger
    tree(int data)
    {
        // Assining the value datat to the class tree data using this->data
        this->data = data;

        // Making the left and right of the node as NULL
        left = right = NULL;
    }
};

// Writing a void function insert that insert a node based on the value if the data is less
// then the root -> data value

void insert(int data, tree *&root)
{
    // Creating a base case that is if root == NULL we add the node to that root and return
    if (root == NULL)
    {
        root = new tree(data);
        return;
    }

    // If the data is less then the root -> data at that node then insert at the left of the data
    if (data < root->data)
    {
        // Using the recursion function to add the data in the tree
        insert(data, root->left);
    }

    // If the data is greater then the root -> data at that node then insert at the right of the data
    if (data > root->data)
    {
        // Using the recursion function to add the data in the tree
        insert(data, root->right);
    }
}

// Doing the preorder traversal of the tree using recursion
// Preorder if root, left, right
void preorder_traversal(tree *root)
{
    // Defining the base condition of the function
    if (root == NULL)
        return;

    // print the root->data
    cout << root->data << " ";

    // Go to the left of the tree
    preorder_traversal(root->left);

    // Go to the right of the tree
    preorder_traversal(root->right);
}

int main()
{
    // Creatign a tree with root as the null
    tree *root = NULL;

    // Inserting values in the tree
    insert(1, root);
    insert(5, root);
    insert(10, root);
    insert(2, root);
    insert(4, root);
    insert(3, root);

    // Printing the tree in preorder traversal
    preorder_traversal(root);

    return 0;
}