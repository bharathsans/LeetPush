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
    int ans = 0;
    int findMax(TreeNode* node){
        if(node == NULL)
            return 0;

        int leftMaxi = findMax(node->left);
        int rightMaxi = findMax(node->right);

        int maxi = node->val + max({leftMaxi, rightMaxi, 0});
        ans = max({ans, maxi, node->val + leftMaxi + rightMaxi});

        return maxi;
    }
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        findMax(root);
        return ans;
    }
};