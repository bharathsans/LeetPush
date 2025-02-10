// Find longest palindromic subsequence...
// The remaining elements needs another element to be added...
// Alternate ques : Minumum delitions to make string palindrome...

class Solution {
public:

    int findLPS(int l, int r, string& s, vector<vector<int>>& dp){
        if(l == r)
            return 1;
        else if(l > r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        if(s[l] != s[r]){
            return dp[l][r] = max(findLPS(l + 1, r, s, dp), findLPS(l, r - 1, s, dp));
        }
        else{
            return dp[l][r] = 2 + findLPS(l + 1, r - 1, s, dp);
        }
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return n - findLPS(0, n - 1, s, dp);
    }
};