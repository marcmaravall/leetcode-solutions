class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for (auto& sentence : sentences) {
            int current = 1;
            for (char c : sentence) {
                if (c == ' ')
                    current++;
            }
            res = max(res, current);
        }
        return res;
    }
};