#include <iostream>
#include <queue>
#include <map>

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

void topView(Node* root) {
    if (root == nullptr)
        return;

    map<int, int> topViewMap;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        Node* node = curr.first;
        int hd = curr.second;

        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->data;
        }

        if (node->left != nullptr) {
            q.push({node->left, hd - 1});
        }

        if (node->right != nullptr) {
            q.push({node->right, hd + 1});
        }
    }

    cout << "Top view of the binary tree: ";
    for (auto const& [hd, val] : topViewMap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter root value (-1 for NULL): ";
    Node* root = createTree();

    topView(root);

    return 0;
}