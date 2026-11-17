#include <iostream>
#include <algorithm>
#include <climits>

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

struct Info {
    int isBST;
    int min;
    int max;
    int sum;
};

int maxSum = INT_MIN;

Info maxSumBST(Node* root) {
    if (root == nullptr) {
        return {1, INT_MAX, INT_MIN, 0};
    }

    Info left = maxSumBST(root->left);
    Info right = maxSumBST(root->right);

    Info info;

    if (left.isBST && right.isBST && root->data > left.max && root->data < right.min) {
        info.isBST = 1;
        info.sum = left.sum + right.sum + root->data;

        info.min = (root->data < left.min) ? root->data : left.min;
        info.max = (root->data > right.max) ? root->data : right.max;

        if (info.sum > maxSum)
            maxSum = info.sum;
    } else {
        info.isBST = 0;
        info.min = INT_MIN;
        info.max = INT_MAX;
        info.sum = 0;
    }

    return info;
}

int main() {
    cout << "Enter root value (-1 for NULL): ";
    Node* root = createTree();

    maxSumBST(root);

    cout << "Maximum BST subtree sum = " << maxSum << endl;

    return 0;
}