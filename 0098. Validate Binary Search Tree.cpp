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
private:
    bool isValidBSTRec(TreeNode* root, long long int min, long long int max)
    {
        if (!root)
            return true;

        return (root->val > min && root->val < max && isValidBSTRec(root->left, min, root->val) && isValidBSTRec(root->right, root->val, max));
    }

public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        return isValidBSTRec(root, -2147483649, 2147483648);
    }
};