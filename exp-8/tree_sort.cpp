#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int ele) {
    if (root == nullptr) {
        Node* tmp = new Node(ele);
        return tmp;
    }

    if (ele < root->data)
        root->left = insert(root->left, ele);
    else
        root->right = insert(root->right, ele);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n, ele;
    Node* root = nullptr;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements.\n";
        return 0;
    }

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> ele;
        root = insert(root, ele);
    }

    cout << "Sorted array: ";
    inorder(root);
    cout << "\n";

    return 0;
}