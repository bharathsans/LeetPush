class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 2, 0);
        dp[0] = 1; // No elements 1 way...
        dp[1] = 1; // 1 element 1 way...
        dp[2] = 2; // 1 is root or 2 is root...

        for(int sz = 3; sz <= n; sz++){
            // Go for each element as root, and sum up...
            for(int left = 0; left <= sz - 1; left++){
                int right = sz - left - 1; 
                dp[sz] += (dp[left] * dp[right]);
            }
        }

        return dp[n];
    }
};