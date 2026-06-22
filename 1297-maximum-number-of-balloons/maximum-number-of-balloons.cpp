class Solution {
public:
    int maxNumberOfBalloons(string text) {
        return rearrangeCharacters(text, "balloon");
    }

    int rearrangeCharacters(string s, string target) {
        std::vector<int> freqs(52);
        
        for (char c : s) freqs[c-'a']++;
        for (char c : target) freqs[c-'a'+26]++;

        int res = INT_MAX;
        for (char c : target) {
            res = min(res, freqs[c-'a'] / freqs[c-'a'+26]);
        }

        return res;
    }
};