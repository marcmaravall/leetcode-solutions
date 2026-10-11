class Solution {
public:
    string removeStars(string s) {
        std::stack<int> st;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                int top = st.top();
                st.pop();
                s[top] = ' ';
            } else 
                st.push(i);
        }
        std::string res = "";
        for (char c : s)
            if (c != ' ' && c != '*')
                res += c;
        return res;
    }
};