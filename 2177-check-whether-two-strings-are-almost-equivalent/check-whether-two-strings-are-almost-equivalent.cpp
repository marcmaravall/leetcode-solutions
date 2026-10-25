class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int freq[26] = {};
        for (char c : word1) {
            freq[c-'a']++;
        }
        for (char c : word2) {
            freq[c-'a']--;
        }
        for (int f : freq) {
            if (f*f > 9)
                return false;
        }
        return true;
    }
};