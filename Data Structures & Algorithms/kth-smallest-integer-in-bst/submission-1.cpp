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
    void DFS(TreeNode* root, int &k,int &value){
        if(!root) return ;

        DFS(root->left,k,value);
        k--;
        if(k==0) value=root->val;
        DFS(root->right,k,value);
    }

    int kthSmallest(TreeNode* root, int k) {
        //now try optimized way
        int val=-1;
        DFS(root,k,val);
        return val;
    }
};
