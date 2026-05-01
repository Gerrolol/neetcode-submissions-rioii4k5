class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        set<int>usedIndex;
        int len = nums.size();
        int start = 0;
        int startVal = nums[start];
        int count = 0;
        while(count < len){
            while(usedIndex.find(start) != usedIndex.end()){
                start++;
                startVal = nums[start];
            }
            int nextIndex = (start + k) % len;
            int nextVal = nums[nextIndex];
            usedIndex.insert(start);
            nums[nextIndex] = startVal;
            start = nextIndex;
            startVal = nextVal;
            count++;
        }
    }
};