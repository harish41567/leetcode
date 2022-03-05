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
    void findkthSmallest(TreeNode* root, int k , int &cnt, int &ans)
    {
        if (!root)
            return;

        findkthSmallest(root->left, k, cnt, ans);
        if (cnt == k)
        {
            ans = root->val;
            cnt++;
            return;
        }
        cnt++;
        findkthSmallest(root->right, k, cnt, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 1, ans = -1;
        findkthSmallest(root, k, cnt, ans);
        return ans;
    }
};
