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
    void DFS(TreeNode* root,int maxi,int &count){
        if(!root) return ;

        if(root->left){
            if(root->left->val >= maxi){
                count++;
            }
            int leftmax=max(maxi,root->left->val);
            DFS(root->left,leftmax,count);
        }
        if(root->right){
            if(root->right->val >= maxi){
                count++;
            }
            int rightmax=max(maxi,root->right->val);
            DFS(root->right,rightmax,count);
        }
    }

    int goodNodes(TreeNode* root) {
        int count=1;
        DFS(root,root->val,count);
        return count;
    }
};
