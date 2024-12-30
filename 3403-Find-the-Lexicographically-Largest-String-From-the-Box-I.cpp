class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)
            return word;
        
        int maxLen = word.size() - numFriends + 1;
        string ans = "";
        
        // Substr when it goes out of bounds
        // Just takes whatever remains...
        for(int i = 0; i < word.size(); i++)
            ans = max(ans, word.substr(i, maxLen));

        return ans;
    }
};
