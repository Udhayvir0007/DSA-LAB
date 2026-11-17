#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class bt{
    public:
    TreeNode* buildtree(vector<int> & nodes){
        if(nodes.empty()||nodes[0]==-1) return nullptr;
        TreeNode* root = new TreeNode(nodes[0]);
        queue<TreeNode*> q;
        q.push(root);
        int cnt=1;
        while (!q.empty()&&cnt<nodes.size())
        {
            TreeNode* curr= q.front();
            q.pop();
            if(cnt<nodes.size() && nodes[cnt]!=-1){
                curr->left= new TreeNode(nodes[cnt]);
                q.push(curr->left);
            }
            cnt++;
            if(cnt<nodes.size() && nodes[cnt]!=-1){
                curr->right= new TreeNode(nodes[cnt]);
                q.push(curr->right);
            }
            cnt++;
        }
        return root;  
    }
    bool is_mirror(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        if(!node1|| !node2) return false;
        return (node1->val == node2->val) && is_mirror(node1->left, node2->right) && is_mirror(node1->right, node2->left);

    }
    bool is_symm(TreeNode*root){
        if(!root) return false;
        return is_mirror(root->left, root->right);
    }
    void print_tree(TreeNode* root){
        if(!root) return;
        print_tree(root->left);
        cout << root->val<< " ";
        print_tree(root->right);
    }

};
int main(){
    bt bintree;
    vector<int> arr1 = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root1 = bintree.buildtree(arr1);
    cout << "Tree is symmtreic? :"<<bintree.is_symm(root1)<< endl;
    vector<int> arr2 = {1, 2, 2, -1, 3, -1, 3};
    TreeNode* root2 = bintree.buildtree(arr2);
     cout << "Tree is symmtreic? :"<<bintree.is_symm(root2)<< endl;
}