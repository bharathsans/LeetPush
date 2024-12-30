class Solution {
public:

    bool isPossible(vector<int>& count){
        int same = -1;
        for(int i = 0; i < 26; i++){
            if(count[i] != 0)
            {
                if(same == -1)
                    same = count[i];
                else
                    if(count[i] != same)
                        return false;
            }
        }
        return true;
    }

    int findMin(string s, int start, vector<int>& dp){

        if(start == s.size())
            return 0;
        
        if(dp[start] != -1)
            return dp[start];

        int ans = INT_MAX - 2;
        vector<int> count(26, 0);
      
        for(int i = start; i < s.size(); i++){
            count[s[i] - 'a']++;
            if(isPossible(count))
                ans = min(ans, findMin(s, i + 1, dp) + 1);
        }
        
        return dp[start] = ans;
    }


    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return findMin(s, 0, dp);
    }
};