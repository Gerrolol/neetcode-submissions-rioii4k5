class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>store;
        store[0] = 1;
        int currSum = 0; 
        int ans = 0;

        for(int n : nums){
            currSum += n;
            if(store.find(currSum - k) != store.end()){
                ans += store[currSum - k];
            }
            store[currSum]++;
        }
        return ans;
    }
};