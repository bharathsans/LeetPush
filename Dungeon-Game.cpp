class Solution {
public:
    int n, m;
    const int INF = 1e9;
    int findBest(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        if(i < 0 || i >= n || j < 0 || j >=m)
            return INF;
        if((i == (n - 1)) && (j == (m - 1))){
            if(dungeon[i][j] <= 0)
                return abs(dungeon[i][j]) + 1;
            else
                return 1;
        }
        if(dp[i][j] != INF)
            return dp[i][j];
        int goRight = findBest(i + 1, j, dungeon, dp);
        int goDown = findBest(i, j + 1, dungeon, dp);
        int minHealth = -dungeon[i][j];
        minHealth += min(goDown, goRight);
        return dp[i][j] = ((minHealth <= 0) ? 1 : minHealth);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(); m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
        return findBest(0, 0, dungeon, dp);
    }
};