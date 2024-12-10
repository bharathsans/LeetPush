class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        vector<int> prev;

        for(int i = 1; i <= numRows; i++){

            vector<int> cur;
            cur.push_back(1);

            for(int j = 1; j <= i - 2; j++)
                cur.push_back(prev[j - 1] + prev[j]);

            if(i != 1)
                cur.push_back(1);
            
            prev = cur;
            ans.push_back(cur);
        }

        return ans;

    }
};