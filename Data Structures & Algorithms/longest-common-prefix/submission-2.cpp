class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        priority_queue<int, vector<int>, greater<>>min_heap;
        string compare = strs[0];
        for(int i=1; i<strs.size(); i++){
            int counter = 0;
            for(int j=0; j<compare.size(); j++){
                if(compare[j] == strs[i][j]){
                    counter++;
                }else{
                    break;
                }
            }
            min_heap.push(counter);
        }
        int longest = min_heap.top(); 
        cout << longest;
        return compare.substr(0,longest);
    }
};