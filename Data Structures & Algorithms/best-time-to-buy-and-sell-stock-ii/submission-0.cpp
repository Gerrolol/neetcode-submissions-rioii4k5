class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }
        return totalProfit;
    }
};

/*
1,1,3,1,5
^       ^

p = 0
7,1,5,3,6,4
^         ^


*/