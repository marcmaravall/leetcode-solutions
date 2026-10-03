class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        const int n = s.size();
        std::stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
                continue;
            }
            st.pop();
            if (st.empty())
                st.push(i);
            else res = std::max(res, i-st.top());
        }
        return res;
    }
};