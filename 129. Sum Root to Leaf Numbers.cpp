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
    int sum(TreeNode* root, int pathSum)
    {
        if(root==NULL)
            return 0;
        
        pathSum = pathSum*10 + root->val;
        
        if(!root->left && !root->right)
            return pathSum;
        
        return sum(root->left, pathSum) + sum(root->right, pathSum);
    }
    
    
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
};