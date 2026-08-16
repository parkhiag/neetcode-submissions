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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==NULL) return "#,";
        queue<TreeNode*> q;
        q.push(root);
        string s="";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node==NULL) {
                s+="#,";
                continue;
            }
            s+=to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#,") return NULL;
        stringstream ss(data);
        string token;
        vector<string> tokens;

        // getline will read the string till we find any ','

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (tokens[i]!="#") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;
            if (tokens[i]!="#") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};
