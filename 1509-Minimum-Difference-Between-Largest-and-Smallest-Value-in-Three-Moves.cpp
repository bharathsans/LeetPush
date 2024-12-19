class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n <= 4)
            return 0;

        int ans = INT_MAX;
        for(int i = 3, j = n - 1; i >= 0; --i, --j)
            ans = min(ans, nums[j] - nums[i]);

        return ans;
    }
};