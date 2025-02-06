class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> len;
        for(auto& num: nums){
            auto it = lower_bound(len.begin(), len.end(), num);
            if(it == len.end())
                len.push_back(num);
            else
                *it = num;
        }
        return len.size();
    }
};