class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer;

        for(int i = 0; i < n; i++){
            int currentSum = 0;

            for(int j = 0; j < n; j++){
                if(boxes[j] == '1' && i != j){
                    currentSum += abs(j - i);
                }
            }
            answer.push_back(currentSum);
        }
        return answer;
    }
};