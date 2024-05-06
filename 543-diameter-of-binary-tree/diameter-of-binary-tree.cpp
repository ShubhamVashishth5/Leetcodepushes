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
    int diameterOfBinaryTree(TreeNode* root) {
        int max=0;
        maxDiameter(root, max);
        return max ;
        // if(root==NULL)return 0;
        // int diameter= maxDepth(root->left)+maxDepth(root->right);
        // return std::max({diameter, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right) });
    }

    int maxDiameter(TreeNode *root, int &diameter){
        if(root==nullptr)return 0;
        int leftDiam= maxDiameter(root->left,diameter);
        int rightDiam= maxDiameter(root->right,diameter);
        diameter= max(leftDiam+rightDiam, diameter);
        return 1+ max(leftDiam, rightDiam); 
    }

     int maxDepth(TreeNode* root) {
        if(root== NULL)return 0;
        int left = maxDepth(root->left);  
        int right = maxDepth(root->right);  
      
        if (right>left)  
            return(right + 1);  
        else return(left + 1);  
    
        
    }

    bool comp(int a, int b) 
{ 
  return (a < b); 
}
};