class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> st;
        int left = 0, right = 0;
        const int n = pushed.size();
        while (left < n && right < n) {
            st.push(pushed[left]);
            while (!st.empty() && st.top() == popped[right]) {
                right++;
                st.pop();
            }
            left++;
        }
        return left == n && right == n;
    }
};