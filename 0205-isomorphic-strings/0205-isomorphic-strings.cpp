class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0}; // Mapping of each character of language s to language t
        bool istCharsMapped[256] = {0}; // Stores if t[i] character is already mapped with s[i]

        for(int i = 0; i < s.size(); i++) {
            if(hash[s[i]] == 0 && istCharsMapped[t[i]] == 0) {
                // Establish the mapping if not already mapped
                hash[s[i]] = t[i];
                istCharsMapped[t[i]] = true;
            }
            else if(hash[s[i]] != t[i]) {
                // If already mapped and the mapping is incorrect
                return false;
            }
        }
        return true;
    }
};
