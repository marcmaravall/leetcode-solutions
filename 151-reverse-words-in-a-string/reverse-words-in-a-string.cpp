class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        std::vector<std::string> words;
        
        std::istringstream isstream(s);
        std::string temp = "";
        while (isstream >> temp) {
            words.push_back(temp);
        }

        std::reverse(words.begin(), words.end());
        s = "";
        for (std::string w : words) {
            s += w;
            s += " ";
        }
        s.pop_back();

        return s;
    }
};