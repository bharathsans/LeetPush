class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> prev;
        vector<int> cur;

        for(int i = 1; i <= rowIndex + 1; i++){

            vector<int> cur;
            cur.push_back(1);

            for(int j = 1; j <= i - 2; j++)
                cur.push_back(prev[j - 1] + prev[j]);

            if(i != 1)
                cur.push_back(1);
            
            prev = cur;
        }

        return prev;
    }
};