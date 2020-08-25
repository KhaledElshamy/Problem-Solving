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
    
    long long maximum = 0 ;
    int sumOfAllNodes;
    int mod = 1000000007;
    
    int getSumOfNodes(TreeNode* root){
        if(root == NULL)return 0;
        int left = getSumOfNodes(root->left);
        int right = getSumOfNodes(root->right);
        
        return left + right + root->val;
    }
    
    
    
    long long getMaxProduct(TreeNode* root){
        if(root == NULL)return 0;
        
        
        int left = getMaxProduct(root->left);
        int right = getMaxProduct(root->right);
        
        long long sum = left + right + root->val;
        
        maximum = max(maximum,sum*(sumOfAllNodes - sum));
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        sumOfAllNodes = getSumOfNodes(root);
        getMaxProduct(root);
        return maximum % mod;
    }
};
