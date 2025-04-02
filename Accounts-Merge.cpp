class Solution {
public:
    int find(int person, vector<int>& Rep){
        if(Rep[person] == person)
            return person;
        return Rep[person] = find(Rep[person], Rep);
    }
    void unions(int person1, int person2, vector<int>& Rep){
        Rep[find(person1, Rep)] = find(person2, Rep);
        // Union by rank/ size TBD...
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> Rep(n + 1);
        for(int i = 0; i < n; i++){
           Rep[i] = i;
        }
        unordered_map<string, int> emailToId;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string name = accounts[i][0];
                string email = accounts[i][j];
                if(emailToId.find(email) == emailToId.end()){
                    emailToId[email] = i;
                }
                else{
                    unions(i, emailToId[email], Rep);
                }
            }
        }
        unordered_map<int, set<string>> mergedAcc;
        for(auto [email, id]: emailToId){
            mergedAcc[find(id, Rep)].insert(email);
        }
        vector<vector<string>> ans;
        for(auto it: mergedAcc){
            vector<string> cur = {accounts[it.first][0]};
            for(auto emails: it.second){
                cur.push_back(emails);
            }
            ans.push_back(cur);
        }       
        return ans;
    }
};