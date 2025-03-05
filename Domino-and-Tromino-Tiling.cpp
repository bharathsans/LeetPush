#define ll long long
class Solution {
public:
    ll MOD = 1e9 + 7;
    ll find(int ind, bool gap, int n, vector<vector<int>>& dp){
        if(ind > n)
            return 0;
        if(ind == n)
            return 1;
        if(ind == (n - 1))
            return 2;
        if(dp[ind][gap] != -1)
            return dp[ind][gap];
        ll ans = 1;
        if(!gap){
            ll pos1 = find(ind + 2, 0, n, dp) % MOD;
            ll pos2 = find(ind + 1, 0, n, dp) % MOD;
            ll pos3 = (2 * find(ind + 2, 1, n, dp)) % MOD;
            ans = (pos1 + pos2 + pos3) % MOD;
        }
        else{
            ll pos1 = find(ind + 1, 1, n, dp) % MOD;
            ll pos2 = find(ind + 1, 0, n, dp) % MOD;
            ans = (pos1 + pos2) % MOD;
        }
        return dp[ind][gap] = ans % MOD;
    }
    int numTilings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        ll ways = find(0, 0, n - 1, dp);
        return ways;
    }
};