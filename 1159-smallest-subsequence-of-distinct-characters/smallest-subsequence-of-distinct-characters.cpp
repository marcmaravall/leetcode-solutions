class Solution {
public:
    string smallestSubsequence(string s) {
        std::vector<int> lastIndex(26, 0);
        const int n = s.size();
        
        for (int i = 0; i < n; i++){
            lastIndex[s[i] - 'a'] = i;
        }
        
        std::vector<bool> seen(26, false); 
        std::stack<char> st;
        
        for (int i = 0; i < n; i++) {
            int curr = s[i] - 'a';
            
            if (seen[curr]) 
                continue;
            
            while(st.size() > 0 && st.top() > s[i] && i < lastIndex[st.top() - 'a']){
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[curr] = true;
        }
        
        std::string res = "";
        while (st.size() > 0){
            res += st.top();
            st.pop();
        }

        std::reverse(res.begin(), res.end());
        
        return res;
    }
};