class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};

        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
        }
        //find the most occuring character
        char maxOccChar;
        int maxOcc = INT_MIN;
        for(int i = 0; i < 26; i++){
            if(hash[i] > maxOcc){
                maxOcc = hash[i];
                maxOccChar = i + 'a';
            }
        }
        int index = 0;
        while(maxOcc > 0 && index < s.size()){
            s[index] = maxOccChar;
            maxOcc--;
            index += 2;
        }
        if(maxOcc != 0){
            return "";
        }
        hash[maxOccChar - 'a'] = 0;

        //let's place the rest of the characters
        for(int i = 0; i < 26; i++){
            while(hash[i] > 0){
                index = index  >= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};