class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        
        int r = m.size();
        int c = m[0].size();

        vector<vector<int>> dp(r, vector<int>(c, 0));
        int ans = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){ 
                if(m[i][j] == '1'){
                    int mini = INT_MAX;
                    if(i > 0 && j > 0)
                        mini = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                    
                    if(mini == INT_MAX)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 + mini;      
                    ans = max(ans, dp[i][j] * dp[i][j]);
                }
            } 
            cout << endl;
        }

        
        return ans;

    }
};