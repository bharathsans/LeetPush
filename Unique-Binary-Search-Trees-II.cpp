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
    map<pair<int,int>, vector<TreeNode*>> dp;
    int N;
    vector<TreeNode*> helper(int st, int end){
        if(st > end){
            return {NULL};
        }
        if(dp.count({st, end}) > 0)
            return dp[{st, end}];
        vector<TreeNode*> ans;
        for(int root = st; root <= end; root++){
            vector<TreeNode*> left = helper(st, root - 1);
            vector<TreeNode*> right = helper(root + 1, end);
            for(auto l: left){
                for(auto r: right){
                    TreeNode* tn = new TreeNode(root, l, r);
                    ans.push_back(tn);
                }
            }
        }
        return dp[{st, end}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        N = n;
        return helper(1, n);
    }
};