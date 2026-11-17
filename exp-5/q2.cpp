#include <iostream>
#include <queue>
#include <vector>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
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
class soln{
    public:
    int min_depth(TreeNode* root){
        if(!root) return 0;
        if(!root->left) return 1+min_depth(root->right);
        if(!root->right) return 1+ min_depth(root->left);
        return 1+ min(min_depth(root->left), min_depth(root->right));
    }
};
int main(){
    soln sl;
    vector<int> arr1 = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root= buildtree(arr1);
    cout << "Minimum depth of tree is:"<< sl.min_depth(root);
}