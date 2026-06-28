class Solution {
public:
    bool valid(std::string& a, std::string& b) {
        bool found = false;
        const int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (found)
                    return false;
                found = true;
            }
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 1;
        std::queue<std::string> q;
        std::unordered_map<std::string_view, bool> memo;
        q.push(beginWord);
        memo[beginWord] = true;

        while (!q.empty()) {
            size_t s = q.size();
            for (int i = 0; i < s; i++) {
                std::string current = q.front();
                q.pop();
                if (current == endWord)
                    return res;
                for (auto& str : wordList) {
                    if (!memo[str] && valid(current, str)) {
                        q.push(str);
                        memo[str] = true;
                    }
                }
            }
            res++;
        }

        return 0;
    }
};