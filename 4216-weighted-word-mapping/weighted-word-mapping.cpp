class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        std::string res = "";

        for (std::string& word : words) {
            int current = 0;
            for (char c : word) {
                current += weights[c-'a'];
            }
            
            current %= 26;
            res += 'z' - (char)current;
        }
        
        return res;
    }
};