class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> lis;
        lis.push_back(obstacles[0]);
        ans.push_back(1);
        for(int i = 1; i < obstacles.size(); i++){
            auto it = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if(it == lis.size())
                lis.push_back(obstacles[i]);
            else
                lis[it] = obstacles[i];
            ans.push_back(it + 1);
        }
        return ans;
    }
};