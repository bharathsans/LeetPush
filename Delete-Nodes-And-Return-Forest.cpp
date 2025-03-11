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
    vector<TreeNode*> ans;
    void dfs(TreeNode*& cur, TreeNode* root, set<int> s){
        if(cur == NULL)
            return;
        if(s.find(cur->val) !=s.end()){
            dfs(cur->left, cur->left, s);
            dfs(cur->right, cur->right, s);
            cur = NULL;
        }
        else{
            if(cur->val == root->val)
                ans.push_back(root);
            dfs(cur->left, root, s);
            dfs(cur->right, root, s);
        }
        return;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s(to_delete.begin(), to_delete.end());
        dfs(root, root, s);
        return ans;
    }
};