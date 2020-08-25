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
   
    TreeNode* xNode;
    TreeNode* getxNode(TreeNode* root,int x){
        if(root == NULL)return NULL ;
        else {
            if(root->val == x){xNode = root;return root;}
            getxNode(root->left,x);
            getxNode(root->right,x);
        }
        
        return root;
    }
    
    
    int getNumberOfNodesOfXNodeTree(TreeNode* root){
        if(root == NULL)return 0;
        
        int left = getNumberOfNodesOfXNodeTree(root->left);
        int right = getNumberOfNodesOfXNodeTree(root->right);
        
        return 1 + (left + right);
    }
    
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        getxNode(root,x);
        
        
        int numOfLeftNodesOfX = getNumberOfNodesOfXNodeTree(xNode->left);
        int numOfRightNodesOfX = getNumberOfNodesOfXNodeTree(xNode->right);
        
        if(numOfLeftNodesOfX > n/2 || numOfRightNodesOfX > n/2)return true;
        
        if(numOfLeftNodesOfX + numOfRightNodesOfX + 1 < (n+1) /2)return true;
        
        return false;
    }
};
