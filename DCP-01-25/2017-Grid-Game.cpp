class Solution {
public:


    long long gridGame(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> totSum(2, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                totSum[i] += grid[i][j];
            }
        }

        long long upSum = 0;
        long long downSum = 0;
        long long ans = LLONG_MAX;

        for(int j = 0; j < m; j++){
            upSum += grid[0][j];
            
            long long upAvail = totSum[0] - upSum;
            long long downAvail = downSum;

            ans = min(ans, max(upAvail, downAvail));

            downSum += grid[1][j];
        }

        return ans;
    }
};