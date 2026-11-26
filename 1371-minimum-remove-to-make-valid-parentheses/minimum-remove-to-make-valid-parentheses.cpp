class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int n = s.size();
        int depth = 0;
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                depth++;
                st.push(i);
            } else if (s[i] == ')') {
                depth--;
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '\0';
                }
            }
        }
        while (!st.empty()) {
            s[st.top()] = '\0';
            st.pop();
        }
        std::string res = "";
        for (char c : s) {
            if (c) {
                res += c;
            }
        }
        return res;
    }
};