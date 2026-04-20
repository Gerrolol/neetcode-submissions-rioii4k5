class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ptr1 = 0;
        int ptr2 = 0;
        string finalstr = "";
        while(ptr1 < word1.size() || ptr2 < word2.size()){
            if(ptr1 < word1.size()){
                finalstr += word1[ptr1];
                ptr1++;
            }
            if(ptr2 < word2.size()){
                finalstr += word2[ptr2];
                ptr2++;
            }
        }
        return finalstr;
    }
};