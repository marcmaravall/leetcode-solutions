class Solution {
public:
    string truncateSentence(string s, int k) {
        std::stringstream ss(s);
        std::string word = "";
        std::string res = "";

        for (int i = 0; i < k && std::getline(ss, word, ' '); i++) {
            res += word;
            if (i != k-1)
                res += " ";
        }

        return res;
    }
};