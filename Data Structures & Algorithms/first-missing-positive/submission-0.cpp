class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        
        for(int i=0; i<len; i++){
            while(nums[i] != i+1 && nums[nums[i] - 1] != nums[i]){
                if(nums[i] <= 0 || nums[i] > len){
                    break;
                }
                int index = nums[i] - 1;
                int temp = nums[index];
                nums[index] = nums[i]; 
                nums[i] = temp;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return len +1;
    }
};