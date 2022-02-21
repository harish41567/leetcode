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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &map, int &preIndex, int is, int ie)
    {
        if (is > ie)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int index = map[root->val];

        root->left = buildTreeHelper(preorder, inorder, map, preIndex, is, index - 1);
        root->right = buildTreeHelper(preorder, inorder, map, preIndex, index + 1, ie);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        int preIndex = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
            map[inorder[i]] = i;

        return buildTreeHelper(preorder, inorder, map, preIndex, 0, n - 1);
    }
};