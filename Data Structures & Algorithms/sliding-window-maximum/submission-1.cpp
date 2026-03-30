class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res;
        deque<int>dq;
        int left= 0, right = 0;
        while(right < n){
            while(!dq.empty() && nums[right] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(right);

            if(left > dq.front()){
                dq.pop_front();
            }
            
            if(right-left+1 >= k){
                res.push_back(nums[dq.front()]);
                left++;
            }
            right++;
        }
        return res;
    }
};
