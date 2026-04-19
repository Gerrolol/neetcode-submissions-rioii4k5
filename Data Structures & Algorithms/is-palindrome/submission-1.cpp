class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            cout << "left : " << s[left] << " " << "right: " << s[right] << endl;
            while(!isdigit(s[left]) && !isalpha(s[left]) && left < s.size()){
                left++;
                cout << "left:" << left << endl;
            }
            while(!isdigit(s[right]) && !isalpha(s[right]) && right >= 0){
                right--;
                cout << "right:" << right << endl;
            }
            if(tolower(s[right]) != tolower(s[left])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
