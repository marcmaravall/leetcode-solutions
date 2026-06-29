class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t start = s.find(part);
        if (start == std::string::npos)
            return s;
        s.erase(start, part.size());
        return removeOccurrences(s, part);
    }
};