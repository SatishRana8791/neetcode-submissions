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
    int DFS(TreeNode* root,int &maxi){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        

        int left_max=DFS(root->left,maxi);
        int right_max=DFS(root->right,maxi);

        maxi=max(maxi,left_max+right_max);
        return 1+max(left_max,right_max);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root || (!root->left && !root->right)) return 0;
        int maxi=INT_MIN;
        DFS(root,maxi);
        return maxi==INT_MIN ? 0 : maxi ;
    }
};
