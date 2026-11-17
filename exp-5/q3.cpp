#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

TreeNode* build_bst(vector<int>& nodes) {
    TreeNode* root = nullptr;

    for (int val : nodes) {
        if (val != -1)
            root = insert(root, val);
    }

    return root;
}

class soln {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr)
            return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    int kth_smallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);

        if (k <= 0 || k > (int)arr.size())
            return -1;

        return arr[k - 1];
    }

    int largest(TreeNode* root) {
        if (root == nullptr)
            return -1;

        while (root->right != nullptr)
            root = root->right;

        return root->val;
    }
};

int main() {
    soln sl;

    vector<int> arr1 = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root = build_bst(arr1);

    cout << "Kth smallest element: " << sl.kth_smallest(root, 3) << '\n';

    cout << "Largest value: "<< sl.largest(root) << '\n';

    return 0;
}