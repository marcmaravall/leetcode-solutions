class Solution {
public:
    string truncateSentence(string s, int k) {
        std::stringstream ss(s);
        std::string word = "";
        std::string res = "";

        for (int i = 0; i < k && std::getline(ss, word, ' '); i++) {
            res += word + " ";
        }
        res.pop_back();

        return res;
    }
};