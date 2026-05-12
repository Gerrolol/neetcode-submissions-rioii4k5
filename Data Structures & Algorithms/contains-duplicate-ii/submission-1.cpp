class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        int r = k;
        if(nums.size()-1 < k){
            r = nums.size()-1;
        }
        while(r < nums.size()){
            for(int i=l+1; i<=r; i++){
                if(nums[i] == nums[l]){
                    return true;
                }
            }
            r++;
            l++;
        }
        return false;
    }  
};
