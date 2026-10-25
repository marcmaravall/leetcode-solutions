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
            if (std::abs(f) > 3)
                return false;
        }
        return true;
    }
};