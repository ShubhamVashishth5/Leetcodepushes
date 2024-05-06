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
    bool isBalanced(TreeNode* root) {
        bool isBalanced= true;
        maxH(root, isBalanced);
        return isBalanced;
    }

    int maxH(TreeNode *root, bool &isBalanced){
        if(root==nullptr)return 0;
        int leftH= maxH(root->left, isBalanced);
        int rightH = maxH(root->right, isBalanced);
        if(abs(rightH-leftH)>1)isBalanced=false;
        return 1+ max(leftH, rightH);

    }

};