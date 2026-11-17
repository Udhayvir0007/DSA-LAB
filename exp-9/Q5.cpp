#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
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

void serialize(Node* root, stringstream& ss) {
    if (root == nullptr) {
        ss << "# ";
        return;
    }

    ss << root->data << " ";
    serialize(root->left, ss);
    serialize(root->right, ss);
}

Node* deserialize(stringstream& ss) {
    string val;
    if (!(ss >> val) || val == "#") {
        return nullptr;
    }

    Node* tmp = new Node(stoi(val));
    tmp->left = deserialize(ss);
    tmp->right = deserialize(ss);

    return tmp;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "Enter root value (-1 for NULL): ";
    Node* root = createTree();

    stringstream ss;
    serialize(root, ss);
    string serializedStr = ss.str();

    cout << "Serialized tree: " << serializedStr << endl;

    stringstream ss2(serializedStr);
    Node* newRoot = deserialize(ss2);

    cout << "Inorder traversal of reconstructed tree: ";
    inorder(newRoot);
    cout << endl;

    return 0;
}