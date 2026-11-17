#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor for cleaner initialization
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to build the tree recursively
Node* createTree() {
    int ele;
    cin >> ele;

    if (ele == -1)
        return nullptr;

    Node* tmp = new Node(ele);

    cout << "Enter left child of " << ele << " (-1 for NULL): ";
    tmp->left = createTree();

    cout << "Enter right child of " << ele << " (-1 for NULL): ";
    tmp->right = createTree();

    return tmp;
}

// Function to find the minimum depth of a binary tree
int minDepth(Node* root) {
    if (root == nullptr)
        return 0;

    // If it's a leaf node
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    // If left child is null, recurse down right subtree
    if (root->left == nullptr)
        return 1 + minDepth(root->right);

    // If right child is null, recurse down left subtree
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    // If both children exist, take the minimum of both depths
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    return 1 + min(leftDepth, rightDepth);
}

int main() {
    cout << "Enter root value (-1 for NULL): ";
    Node* root = createTree();

    cout << "Minimum depth: " << minDepth(root) << endl;

    return 0;
}