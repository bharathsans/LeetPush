class DSU{
    public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int ch){
        if(parent[ch] == ch)
            return ch;
        return parent[ch] = find(parent[ch]);
    }
    void unions(int ch1, int ch2){
        parent[find(ch1)] = find(ch2);
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU disjontSet = DSU(26);
        
        for(auto eq: equations){
            int ch1 = eq[0] - 'a';
            int ch2 = eq[3] - 'a';
            if(eq[1] == '='){
                disjontSet.unions(ch1, ch2);
            }
        }
        bool ans = true;
        for(auto eq: equations){
            int ch1 = eq[0] - 'a';
            int ch2 = eq[3] - 'a';
            if(eq[1] == '!'){
                if(disjontSet.find(ch1) == disjontSet.find(ch2)){
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};