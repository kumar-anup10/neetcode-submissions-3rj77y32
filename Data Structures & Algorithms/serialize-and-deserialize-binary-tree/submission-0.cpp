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
        if(!root) return "";

    queue<TreeNode*> q;
    q.push(root);

    string ans = "";

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if(node) {
            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        } else {
            ans += "N,";
        }
    }

    ans.pop_back();
        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;

        vector<string> nodes;
        string temp = "";

        // split by comma
        for(char c : data) {
            if(c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        nodes.push_back(temp);

        // create root
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while(!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // left child
            if(nodes[i] != "N") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;

            // right child
            if(i < nodes.size() && nodes[i] != "N") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};
