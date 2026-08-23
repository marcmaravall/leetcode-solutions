class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int size = 0;
        for (char c : s) {
            if (size + widths[c-'a'] > 100) {
                size = widths[c-'a'];
                lines++;
            } else {
                size += widths[c-'a'];
            }
        }
        return { lines, size };
    }
};