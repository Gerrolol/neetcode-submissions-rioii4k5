class Solution {
public:
    bool isPalindrome(int l, int r, string s){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        int counter = 0;
        while(left < right){
            if(s[left] != s[right] && counter == 0){
                if(isPalindrome(left+1, right, s)){
                    left++;
                }else if(isPalindrome(left, right-1, s)){
                    right--;
                }else{
                    return false;
                }
            }else if(s[left] != s[right] && counter == 1){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};