class Solution {
public:
    string smallestPalindrome(string s) {
        const int n = s.size();
        std::sort(s.begin(), s.begin()+n/2);
        std::sort(s.begin()+std::ceil(n/2.0), s.end(), std::greater<int>());
        return s;
    }
};