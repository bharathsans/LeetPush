class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] > b[1];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {      

        // Sort in decreasing order for Height...
        // As for the same width only one height can be picked during LIS...        
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        vector<int> orderedEnvelope;
        for(auto x: envelopes){
            orderedEnvelope.push_back(x[1]);
        }

        vector<int> lis;
        for(auto &x: orderedEnvelope){
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if(it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }
        return lis.size();
    }
};