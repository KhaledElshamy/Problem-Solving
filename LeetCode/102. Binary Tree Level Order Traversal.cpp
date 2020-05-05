/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (!root){
            return {};
        }
        
        vector<vector<int>> res;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            int size = q.size();
            for(int i= 0;i<size;i++){
                TreeNode* front = q.front(); q.pop();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
                v.push_back(front->val);
            }
            res.push_back(v);
            v.clear();
        }
        return res;
    }
};
