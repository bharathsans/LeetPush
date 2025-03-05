class Solution {
public:
    int n;
    int find(int ind, int prev, vector<vector<int>>& costs, vector<vector<int>>& dp){
        if(ind == (n - 1)){
            int mini = INT_MAX;
            for(int i = 0; i < 3; i++){
                if((i != prev) || (ind == 0))
                    mini = min(mini, costs[n - 1][i]);
            }
            return mini;
        }
        if(dp[ind][prev] != 0)
            return dp[ind][prev];

        int mini = INT_MAX;
        for(int i = 0; i < 3; i++){
            if((i != prev) || (ind == 0)){
                mini = min(mini, costs[ind][i] + find(ind + 1, i, costs, dp));
            }
        }
        return dp[ind][prev] = mini;
    }
    int minCost(vector<vector<int>>& costs) {
        n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        return find(0, 0, costs, dp);
    }
};