#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

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

bool isMirror(Node* x, Node* y) {
    if (!x && !y)
        return true;

    if (!x || !y)
        return false;

    if (x->data != y->data)
        return false;

    return isMirror(x->left, y->right) && isMirror(x->right, y->left);
}

bool isSymmetric(Node* root) {
    if (!root)
        return true;

    return isMirror(root->left, root->right);
}

int main() {
    cout << "Enter root value (-1 for NULL): ";
    Node* root = createTree();

    if (isSymmetric(root))
        cout << "The tree is symmetric.\n";
    else
        cout << "The tree is not symmetric.\n";

    return 0;
}