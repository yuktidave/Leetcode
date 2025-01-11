class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return false;
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }
        int odd = 0;
        for(int x : freq){
            if(x % 2 != 0) odd++;
        }
        return k >= odd;
    }
};