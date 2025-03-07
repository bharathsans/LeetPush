class Solution {
public:
    int n;
    int solve(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp)
    {
        if(i == n)
            return 0;
        if(k <= 0)
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        int prefSum = 0;
        int sum = 0;
        int sz = piles[i].size();
        int noTake = solve(i + 1, k, piles, dp);
        for(int j = 0; j < min(k, sz); j++){
            prefSum += piles[i][j];
            sum = max(sum, prefSum + solve(i + 1, k - (j + 1), piles, dp));
        }
        return dp[i][k] = max(sum, noTake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, piles, dp);
    }
};