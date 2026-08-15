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
    int preindex=0;
    unordered_map<int,int> mpp;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left>right) return NULL;

        int rootvalue = preorder[preindex++];
        TreeNode* root = new TreeNode(rootvalue);

        int mid = mpp[rootvalue];

        root->left = solve(preorder, inorder, left, mid-1);
        root->right = solve(preorder, inorder, mid+1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i=0; i<n; i++) {
            mpp[inorder[i]]=i;
        }
        return solve(preorder, inorder, 0, n-1);
    }
};
