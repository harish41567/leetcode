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
    TreeNode* buildTreeHelper(vector<int>& postorder, vector<int>& inorder, unordered_map<int, int> &map, int &postIndex, int is, int ie)
    {
        if (is > ie)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int index = map[root->val];

        root->right = buildTreeHelper(postorder, inorder, map, postIndex, index + 1, ie);
        root->left = buildTreeHelper(postorder, inorder, map, postIndex, is, index - 1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        int postIndex = n - 1;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
            map[inorder[i]] = i;

        return buildTreeHelper(postorder, inorder, map, postIndex, 0, n - 1);
    }
};