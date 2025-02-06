/*
    Input: pairs = [[1,2],[2,3],[3,4]]
    Output: 2
    Explanation: The longest chain is [1,2] -> [3,4].

    Find minimum deletions required to remove overlapping intervals
    -> Gives maximum chain length
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        int delCount = 0;

        vector<int> prev = pairs[0];

        for(int i = 1; i < n; i++){
            if(prev[1] >= pairs[i][0]){
                delCount++;
                if(prev[1] > pairs[i][1])
                    prev = pairs[i];
            }
            else
                prev = pairs[i];
        }

        return n - delCount;
    }
};