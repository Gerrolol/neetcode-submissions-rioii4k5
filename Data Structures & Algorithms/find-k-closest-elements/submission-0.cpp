class Solution {
public:
    int findPos(vector<int>&arr, int num){
        int left = 0;
        int right = arr.size()-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(arr[mid] < num){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        int right = findPos(arr, x);
        int left = 0; 
        if(right > 0){
            left = right-1;
        }
        while(res.size() < k){
            if(left >= 0 && right <arr.size()){
                if(abs(arr[left] - x) < abs(arr[right] - x)){
                    res.push_back(arr[left]);
                    left--;
                }else if(abs(arr[left] - x) > abs(arr[right] - x)){
                    res.push_back(arr[right]);
                    right++;
                }else if(right == left){
                    res.push_back(arr[right]);
                    right++;
                    left--;
                }else{
                    res.push_back(arr[left]);
                    left--;
                }
            }else if(left < 0){
                res.push_back(arr[right]);
                right++;
            }else if(right > arr.size()-1){
                res.push_back(arr[left]);
                left--;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

/*
binary search for the position of where x would go
then do a two pointer appraoich of the left and right values and pick the smaller values and extend left or right

*/