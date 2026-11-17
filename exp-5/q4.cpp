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
class soln{
    public:
    void inorder(TreeNode * root){
        if(!root) return;
        inorder(root->left);
        cout << root->val<< " ";
        inorder( root->right);
    }
};
int main(){
    soln sl;

    vector<int> arr1 = {2,3,1,4,5,6,7,8,4,5};
    TreeNode* root = build_bst(arr1);
    sl.inorder(root);
    return 0;
}