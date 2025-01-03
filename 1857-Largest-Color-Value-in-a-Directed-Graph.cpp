class Solution {
    typedef array<int, 26> T;
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        map<int, vector<int>> G;
        vector<int> indegree(n, 0);

        for(auto e: edges){
            G[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // cnt[i][colors] -> max count of colors ending at node[i]...
        vector<T> cnt(n, T{});
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
                cnt[i][colors[i] - 'a'] = 1;
            }
        }

        int ans = 0;
        int seen = 0;

        //topo order...
        while(q.size()){
            int cur = q.front();
            q.pop();
            ++seen;

            //O(26)..
            int maxi = *max_element(cnt[cur].begin(), cnt[cur].end());
            ans = max(ans, maxi);

            for(int next: G[cur]){
                for(int i = 0; i < 26; i++){
                    cnt[next][i] = max(cnt[next][i], cnt[cur][i] + (i == colors[next] - 'a'));
                }
                if(--indegree[next] == 0)
                    q.push(next);
            }
        }

        // Not all visited in topo -> cycle exists...
        if(seen < n)
            return -1;
        
        return ans;
    }   
};