class Solution {
public:

    // dp[i][j] -> Longest Palindrome Subsequence startig at i and ending at j
    // dp[i][j] = 2 + dp[i + 1][j - 1] if s[i] == s[j]
    //            max(dp[i + 1][j], dp[i][j - 1])

    int longestPalindromeSubseq(string s) {

        int n = s.size();
        vector<int> dp(n, 0);
        vector<int> prevDp = dp;
        
        for(int i = n - 1; i >= 0; i--){
            dp[i] = 1;

            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j])
                    dp[j] = 2 + prevDp[j - 1];
                else
                    dp[j] = max(prevDp[j], dp[j - 1]);
            }
            prevDp = dp;
        }

        return dp[n - 1];
    }
};