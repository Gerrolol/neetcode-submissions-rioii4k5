class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int>count;
        for(int num: nums){
            count[num]++;
        }
        for(auto[key, freq]: count){
            cout << freq;
            if(freq > n/2){
                return key;
            }
        }
        return -1;
    }
};