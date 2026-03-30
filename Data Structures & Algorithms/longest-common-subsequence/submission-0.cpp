class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>memo(n, vector<int>(m, -1));
        return dfs(0,0, text1, text2, memo);
    }

    int dfs(int i, int j, string text1, string text2, vector<vector<int>>&memo){
        //base case
        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        if(text1[i] == text2[j]){
           memo[i][j] = 1 + dfs(i+1, j+1, text1, text2, memo);
        }else{
           memo[i][j] = max(dfs(i, j+1, text1, text2, memo), dfs(i+1, j, text1, text2, memo));
        }

        return memo[i][j];
    }
};
