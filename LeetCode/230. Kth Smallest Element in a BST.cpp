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
private:
    int ans= INT_MAX, val;
    void kthElement(TreeNode* root,int k){
        if(root == NULL)return;
        kthElement(root->left,k);
        val--;
        if(val == 0)ans = min(ans,root->val);
        kthElement(root->right,k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        val = k;
        kthElement(root,k);
        return ans;
    }
};
