class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int runSum = 0;
        int index = 0;
        dfs(index, runSum, nums, target, res, temp);
        return res; 
        
    }
    
    void dfs(int index, int runSum, vector<int>& nums, int target, vector<vector<int>>&res, vector<int>&temp){
        if(runSum == target){
            res.push_back(temp);
            return;
        }
        
        if(runSum > target){
            return;
        }

        for(int i=index; i<nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(i, runSum + nums[i], nums, target,res, temp);
            temp.pop_back();
        }
    }
};
