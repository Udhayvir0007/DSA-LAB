#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTKthFinder {
private:
    vector<int> sortedElements;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        sortedElements.push_back(root->val);
        inorder(root->right);
    }

public:
    BSTKthFinder(TreeNode* root) {
        inorder(root);
    }

    int findKthSmallest(int k, bool& isValid) {
        if (k < 1 || k > sortedElements.size()) {
            isValid = false;
            return -1; 
        }
        isValid = true;
        return sortedElements[k - 1];
    }
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    vector<int> levelOrder = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    vector<int> queries = {1, 3, 5, 8, 0, 15}; 
    TreeNode* root = buildTree(levelOrder);
    BSTKthFinder bstSolver(root);

    cout << "Query Results:\n";
    for (int k : queries) {
        bool isValid = true;
        int result = bstSolver.findKthSmallest(k, isValid);
        
        if (isValid) {
            cout << "k = " << k << " -> " << result << endl;
        } else {
            cout << "k = " << k << " -> Error: Invalid k (out of bounds)\n";
        }
    }

    return 0;
}