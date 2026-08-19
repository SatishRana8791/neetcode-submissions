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
    void DFS(TreeNode* root, int left,int right,bool & check){
        if(!root) return ;

        if(root->val >= right || root->val <= left){
            check=false;
        }

        DFS(root->left,left,root->val,check);
        DFS(root->right,root->val,right,check);
        
    }

    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return true;
        if(root->val < INT_MIN || root->val > INT_MAX) return false;
        bool valid=true;
        DFS(root,INT_MIN,INT_MAX,valid);
        return valid;
    }
};
