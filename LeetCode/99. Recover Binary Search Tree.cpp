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

void swap( int* a, int* b ) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

class Solution {
public:
    void correctBSTUtil( struct TreeNode* root, struct TreeNode** first, 
                     struct TreeNode** middle, struct TreeNode** last, 
                     struct TreeNode** prev ) 
    { 
        if( root ) 
        { 
            correctBSTUtil( root->left, first, middle, last, prev ); 
            
            if (*prev && root->val < (*prev)->val) 
            { 
                if ( !*first ) { 
                *first = *prev; 
                *middle = root; 
                } 
                else *last = root; 
            }
            
            *prev = root; 
            
            correctBSTUtil( root->right, first, middle, last, prev ); 
        } 
    } 
    
    void recoverTree(TreeNode* root) {
        
        struct TreeNode *first, *middle, *last, *prev; 
        first = middle = last = prev = NULL; 
        
        correctBSTUtil( root, &first, &middle, &last, &prev );
            
        if( first && last ) swap( &(first->val), &(last->val) ); 
        else if( first && middle ) swap( &(first->val), &(middle->val) ); 
    }
};
