class Solution {
public:
    bool isValid(string s) {
        std::string st;
        for (char c : s) {
            if (c == 'c') {
                const int n = st.size();
                if (n < 2 || st[n-1] != 'b' || st[n-2] != 'a')
                    return false;
                st.pop_back();
                st.pop_back();
            } else {
                st += c;
            }
        }
        return st.empty();
    }
};