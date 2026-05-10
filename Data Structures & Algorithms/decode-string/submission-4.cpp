class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> words;

        string curr = "";
        int num = 0;

        for(char c : s) {

            // Build number
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // Enter new bracket scope
            else if(c == '[') {
                nums.push(num);
                words.push(curr);

                num = 0;
                curr = "";
            }

            // Close current scope
            else if(c == ']') {
                int repeat = nums.top();
                nums.pop();

                string prev = words.top();
                words.pop();

                string expanded = "";

                for(int i = 0; i < repeat; i++) {
                    expanded += curr;
                }

                curr = prev + expanded;
            }

            // Normal character
            else {
                curr += c;
            }
        }

        return curr;
    }
};