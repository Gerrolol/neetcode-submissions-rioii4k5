class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>colorCount(3,0);
        for(int i=0; i<nums.size(); i++){
            colorCount[nums[i]]++;
        }
        int index = 0;
        for(int i=0; i<3; i++){
            for(int j=index; j < index + colorCount[i]; j++){
                nums[j] = i;
            }
            index = index + colorCount[i];
        }
    }
};