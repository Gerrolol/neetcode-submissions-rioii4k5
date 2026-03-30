class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right =1;
        int currMax = 0;
        int n = prices.size();
    
        while(right < n){
            if(prices[left] > prices[right]){
                left = right;
            }else{
                currMax = max(currMax, prices[right] - prices[left]);
            }
           right++;
        }
        return currMax;
    }
};
