class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int currSum = 0;
        int currMin = INT_MAX;
        while(right < nums.size()){
            while(currSum >= target){
                currMin = min(currMin, right-left+1);
                if(currSum - nums[left] >= target){
                    currSum -= nums[left];
                    left++;   
                }else{
                    right++;
                    break;
                }
            }
            if(right >= nums.size()){
                break;
            }
            currSum += nums[right];
            if(currSum < target){
                right++;
            }
        }  
        return currSum < target ? 0 : currMin;
    }
};

/*
right = 1 2 3 4 5
left =0 1 2
currSum = 2 3 8 9 14 12 11 14
currMin = 
target = 10
2,1,5,1,5,3 
  ^ ^


target=7
nums=[7,3,1,1,1,1,1,1]

*/