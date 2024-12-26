class Solution {
public:

    bool isPossible(int cur, string s, int numOps){
        
        // Handle 1 case...
        if(cur == 1){
            int n = s.size();
            bool pos1 = 0;
            bool pos2 = 0;

            string s1 = "";
            int diff1 = 0;
            int n1 = n;
            int bit = 0;
            while(n1--){
                s1 += to_string(bit);
                bit ^= 1;
            }
            for(int i = 0; i < n; i++){
                if(s[i] != s1[i])
                    diff1++;
            }

            string s2 = "";
            int diff2 = 0;
            int n2 = n;
            bit = 1;
            while(n2--){
                s2 += to_string(bit);
                bit ^= 1;
            }

            for(int i = 0; i < n; i++){
                if(s[i] != s2[i])
                    diff2++;
            }

            if(diff1 <= numOps || diff2 <= numOps)
                return true;    
            
            return false;
        }


        // Others...
        int curCnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1]){
                ++curCnt;
            }
            else
                curCnt = 1;
            
            if(curCnt > cur && numOps > 0){
                --numOps;
                curCnt = 0;
            }
            else if(curCnt > cur && numOps <= 0)
                return false;
        }
        
        return true;
    }

    int minLength(string s, int numOps) {

        int n = s.size();

        int l = 1;
        int r = n + 1;
        int ans1 = n;
    

        while(l <= r){
            int mid = l + (r - l)/2;

            if(isPossible(mid, s, numOps)){
                ans1 = min(ans1, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
    
        return ans1;
        
    }
};