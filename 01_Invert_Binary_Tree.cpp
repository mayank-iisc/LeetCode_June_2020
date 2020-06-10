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
    
    void mirror(TreeNode* root){
        
        if(root == NULL)
            return;
            
        //recursive call for mirror left subtree
        mirror(root -> left);
        
        //recursive call for mirror left subtree
        mirror(root -> right);
        
        //swap left and right nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;   
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        mirror(root);
        
return root;           
    }
};
