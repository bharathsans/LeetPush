class Solution {
public:
    int numSquares(int n) {
        queue<int> searchQ;
        unordered_map<int, bool> vis;
        searchQ.push(0);
        vis[0] = true;

        int depth = 0;
        while(searchQ.size() > 0){
            int levelSz = searchQ.size();
            depth++;
            while(levelSz--){
                int cur = searchQ.front();
                searchQ.pop();
                for(int i = 1; i * i <= n; i++){
                    int next = cur + i * i;
                    if(next == n)
                        return depth;
                    if(next > n)
                        break;
                    if(!vis[next]){
                        searchQ.push(next);
                        vis[next] = 1;
                    }
                }
            }
        }
        return depth;

        // DP solution : N root(N)
        // vector<int> dp(n+1,INT_MAX);
        // dp[0] = 0;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j*j<=i;j++){
        //         dp[i] = min(dp[i],dp[i-j*j]+1);
        //     }
        // }
        // return dp[n];
    }
};