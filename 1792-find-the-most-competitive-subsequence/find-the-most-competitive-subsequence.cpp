class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        std::stack<int> st {};
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()] && n-i+st.size() > k)
                st.pop();
            if (st.size() < k)
                st.push(i);
        }
        std::vector<int> res(k);
        for (int i = k-1; i >= 0; i--) {
            res[i] = nums[st.top()];
            st.pop();
        }
        return res;
    }
};