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
    int globalMax = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        findMax(root);
        return globalMax;
    }
    
    int findMax(TreeNode*root){
        if(root == nullptr){
            return 0;
        }
        
        int left = findMax(root->left);
        int right = findMax(root->right);
        globalMax = max(globalMax, left+right);
        return 1 + max(left, right);
    }
};
