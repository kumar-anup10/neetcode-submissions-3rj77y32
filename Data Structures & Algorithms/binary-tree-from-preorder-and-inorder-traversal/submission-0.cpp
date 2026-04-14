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
    unordered_map<int,int>m;
    TreeNode* build(vector<int>&pre,vector<int>&in,int &index,int left,int right)
    {
        if(left>right)
        return NULL;

        int val=pre[index++];
        TreeNode *root=new TreeNode(val);
        int pos=m[val];

        root->left=build(pre,in,index,left,pos-1);
        root->right=build(pre,in,index,pos+1,right);
        return root;
    };
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        m[inorder[i]]=i;
        int index=0;
        return build(preorder,inorder,index,0,preorder.size()-1);
    }
};
