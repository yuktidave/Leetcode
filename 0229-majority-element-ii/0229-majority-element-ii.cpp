class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int elt1 = INT_MIN;
        int elt2 = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(count1 == 0 && elt2 != nums[i]){
                count1 = 1;
                elt1 = nums[i];
            }
            else if(count2 == 0 && elt1 != nums[i]){
                count2 = 1;
                elt2 = nums[i];
            }
            else if(nums[i] == elt1) count1++;
            else if(nums[i] == elt2) count2++;
            else{
                count1--;
                count2--;
            }
        }

        vector<int> ls;
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(elt1 == nums[i]) count1++;
            if(elt2 == nums[i]) count2++;
        }
        int mini = (int)(nums.size()/3) + 1;
        if(count1 >= mini) ls.push_back(elt1);
        if(count2 >= mini) ls.push_back(elt2);
        sort(ls.begin(), ls.end());
        return ls;
        
    }
};