#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> distanceK(vector<int>& level_order, int target_val, int K) {
        if (level_order.empty() || level_order[0] == -1) return {};

        TreeNode* root = new TreeNode(level_order[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        
        while (!q.empty() && i < level_order.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (i < level_order.size() && level_order[i] != -1) {
                curr->left = new TreeNode(level_order[i]);
                q.push(curr->left);
            }
            i++;

            if (i < level_order.size() && level_order[i] != -1) {
                curr->right = new TreeNode(level_order[i]);
                q.push(curr->right);
            }
            i++;
        }

        unordered_map<TreeNode*, TreeNode*> parent_map;
        TreeNode* target_node = nullptr;
        
        queue<TreeNode*> parent_q;
        parent_q.push(root);
        
        while (!parent_q.empty()) {
            TreeNode* node = parent_q.front();
            parent_q.pop();

            if (node->val == target_val) {
                target_node = node;
            }

            if (node->left) {
                parent_map[node->left] = node;
                parent_q.push(node->left);
            }
            if (node->right) {
                parent_map[node->right] = node;
                parent_q.push(node->right);
            }
        }

        if (!target_node) return {};

        queue<pair<TreeNode*, int>> bfs_q;
        bfs_q.push({target_node, 0});
        
        unordered_set<TreeNode*> visited;
        visited.insert(target_node);
        
        vector<int> result;

        while (!bfs_q.empty()) {
            auto [node, dist] = bfs_q.front();
            bfs_q.pop();

            if (dist == K) {
                result.push_back(node->val);
                continue;
            }

            vector<TreeNode*> neighbors = {
                node->left, 
                node->right, 
                parent_map.count(node) ? parent_map[node] : nullptr
            };
            
            for (TreeNode* neighbor : neighbors) {
                if (neighbor && visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    bfs_q.push({neighbor, dist + 1});
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> tree_arr = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    int target = 5;
    int K = 2;

    vector<int> ans = sol.distanceK(tree_arr, target, K);
    
    cout << "Nodes at distance " << K << " from " << target;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 < ans.size())<< " ";
    }
     cout<< endl;

    return 0;
}