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
        vector<vector<int>> answer;
        if(root==nullptr)return answer;
            queue<TreeNode*> q; 
            q.push(root);
            TreeNode *node;
            while(q.size()!=0){
                vector<int> ans;
                int size=q.size();
                for(int i=0;i<size;i++){
                node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                ans.push_back(node->val);
                }
                answer.push_back(ans);
            }
            return answer;

    }
};