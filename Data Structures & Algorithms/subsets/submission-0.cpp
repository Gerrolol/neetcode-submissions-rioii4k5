class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        dfs(0,nums,res,temp);
        return res;
        
    }

    void dfs(int index, vector<int>& nums, vector<vector<int>>&res, vector<int>&temp){
        res.push_back(temp);
        if(index >= nums.size()){
            return;
        }
    
        for(int i=index; i<nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(i+1, nums, res,temp);
            temp.pop_back();
        }
    }

};
