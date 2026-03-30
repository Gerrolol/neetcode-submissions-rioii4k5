class Solution {
public:
    // Encodes a list of strings into a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;  // Use '#' as a delimiter
        }
        return encoded;
    }

    // Decodes a single string back into a list of strings.
    vector<string> decode(string s) {
        vector<string> words;
        int i = 0;
        
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s[j] != '#') {
                j++; // Find the '#' delimiter
            }
            int length = stoi(s.substr(i, j - i)); // Extract length of word
            i = j + 1; // Move past '#'
            words.push_back(s.substr(i, length)); // Extract the actual word
            i += length; // Move to next encoded word
        }

        return words;
    }
};
