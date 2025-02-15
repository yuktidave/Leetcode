class Solution {
public:
 static bool comp(vector<int>&v1,vector<int>&v2){
        return v1[1] < v2[1];
        
    }
    int findLongestChain(vector<vector<int>>& pairs){
        sort(pairs.begin(), pairs.end(), comp);
        int cnt = 0;
        int freeTime = 1;
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[cnt][1] < pairs[i][0]){
                cnt = i;
                freeTime++;
            }
        }
        return freeTime;
    }
};