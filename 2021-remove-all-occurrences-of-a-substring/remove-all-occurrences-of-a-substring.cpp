class Solution {
public:
    string removeOccurrences(string s, string part) {
        for (size_t start = s.find(part); start != std::string::npos; start = s.find(part))
            s.erase(start, part.size());
        return s;
    }
};