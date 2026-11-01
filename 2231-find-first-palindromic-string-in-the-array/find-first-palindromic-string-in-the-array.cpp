class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const auto& word : words) {
            const int n = word.size();
            bool palindrome = true;
            for (int i = 0; i < n/2; i++) {
                if (word[i] != word[n-i-1]) {
                    palindrome = false;
                    break;
                }
            }
            if (palindrome) {
                return word;
            }
        }
        return "";
    }
};