#include <iostream>
#include <vector>
#include <cmath>

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

void inorder(Node* root, vector<int>& arr) {
    if (root == nullptr)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void closestK(const vector<int>& arr, int x, int k) {
    int n = arr.size();
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    int i = right, j = left;

    cout << "The " << k << " closest values are: ";

    for (int count = 0; count < k; count++) {
        if (i < 0) {
            cout << arr[j++] << " ";
        } else if (j >= n) {
            cout << arr[i--] << " ";
        } else if (abs(arr[i] - x) <= abs(arr[j] - x)) {
            cout << arr[i--] << " ";
        } else {
            cout << arr[j++] << " ";
        }
    }

    cout << endl;
}

int main() {
    cout << "Enter root value (-1 for NULL): ";
    Node* root = createTree();

    vector<int> arr;
    inorder(root, arr);

    int x, k;
    cout << "Enter target value: ";
    cin >> x;

    cout << "Enter k: ";
    cin >> k;

    if (k <= 0 || k > arr.size()) {
        cout << "Invalid k." << endl;
        return 0;
    }

    closestK(arr, x, k);

    return 0;
}