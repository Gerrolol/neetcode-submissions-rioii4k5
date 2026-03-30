class Solution {
    public int removeElement(int[] nums, int val) {
        int currsize = nums.length;
        int count = currsize;
        int j = 0;
        for(int i =0; i<currsize; i++){
            if(nums[i] == val){
                count -= 1;
            }else{
                nums[j] = nums[i];
                j+=1;
            }
        }
        return count;
    }
}