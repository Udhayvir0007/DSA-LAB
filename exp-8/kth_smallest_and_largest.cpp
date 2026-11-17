#include <iostream>
#include <climits>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTKthSolver {
private:
    bool isValidBSTUtil(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isValidBSTUtil(root->left, minVal, root->val) &&
               isValidBSTUtil(root->right, root->val, maxVal);
    }

    void findSmallest(TreeNode* root, int k, int& count, int& ans) {
        if (!root || count >= k) return;

        findSmallest(root->left, k, count, ans);

        if (count < k) {
            count++;
            if (count == k) {
                ans = root->val;
                return;
            }
        }

        findSmallest(root->right, k, count, ans);
    }

    void findLargest(TreeNode* root, int k, int& count, int& ans) {
        if (!root || count >= k) return;

        findLargest(root->right, k, count, ans);

        if (count < k) {
            count++;
            if (count == k) {
                ans = root->val;
                return;
            }
        }

        findLargest(root->left, k, count, ans);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }

    int getKthSmallest(TreeNode* root, int k) {
        int count = 0, ans = -1;
        findSmallest(root, k, count, ans);
        return ans;
    }

    int getKthLargest(TreeNode* root, int k) {
        int count = 0, ans = -1;
        findLargest(root, k, count, ans);
        return ans;
    }
};

TreeNode* createTree() {
    int ele;
    cout << "Enter node value (-1 for NULL): ";
    cin >> ele;

    if (ele == -1) return nullptr;

    TreeNode* tmp = new TreeNode(ele);

    cout << "Enter left child of " << ele << ":\n";
    tmp->left = createTree();

    cout << "Enter right child of " << ele << ":\n";
    tmp->right = createTree();

    return tmp;
}

int main() {
    cout << "--- Build Binary Search Tree ---\n";
    TreeNode* root = createTree();

    BSTKthSolver solver;

    if (!solver.isValidBST(root)) {
        cout << "\nError: The input tree is NOT a valid Binary Search Tree! In-order queries will fail.\n";
        return 0;
    }

    int k;
    cout << "\nEnter k: ";
    cin >> k;

    if (k <= 0) {
        cout << "Invalid k value.\n";
        return 0;
    }

    int small = solver.getKthSmallest(root, k);
    int large = solver.getKthLargest(root, k);

    if (small == -1) {
        cout << "k exceeds the total number of nodes in the tree.\n";
    } else {
        cout << k << "-th smallest key: " << small << endl;
        cout << k << "-th largest key: " << large << endl;
    }

    return 0;
}