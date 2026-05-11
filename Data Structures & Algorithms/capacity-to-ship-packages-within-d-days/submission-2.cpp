class Solution {
public:
    int requiredDays(vector<int>& weights, int maxCapacity){
        int tempMax = maxCapacity;
        int numDays = 0;
        for(int i=0; i<weights.size(); i++){
            if(tempMax >= weights[i]){
                tempMax -= weights[i];
            }else{
                numDays++;
                tempMax = maxCapacity;
                i--;
            }
        }
        // cout << maxCapacity << " " << numDays+1 << endl;
        return numDays+1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        //first find max 
        int minWeight = 1;
        int maxWeight = 0;
        for(int w : weights){
            minWeight = max(minWeight, w);
            maxWeight += w;
        }
        
        int left = minWeight;
        int right = maxWeight;
        while(left < right){
            cout << left << " " << right << endl;
            int mid = (left + right)/2;
            int dayCount = requiredDays(weights, mid);
            if(dayCount <= days){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};