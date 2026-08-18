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
    int DFS(TreeNode* root,bool &valid){
        if(!root) return 0;

        int left_max=DFS(root->left,valid);
        int right_max=DFS(root->right,valid);

        if(abs(left_max - right_max) > 1){
            valid=false;
        }
        return 1+max(left_max,right_max);
    }

    bool isBalanced(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return true;
        bool valid=true;
        DFS(root,valid);
        return valid;
    }
};
