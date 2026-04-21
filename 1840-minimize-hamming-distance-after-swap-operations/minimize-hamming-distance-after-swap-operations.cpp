class Solution {
public:
    std::vector<int> parent = {};

    int find(const int n) {
        if (parent[n] != n)
            parent[n] = find(parent[n]);
        return parent[n];
    }

    void _union(const int a, const int b) {
        parent[find(a)] = find(b);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (const std::vector<int>& sw : allowedSwaps) {
            _union(sw[0], sw[1]);
        }

        std::unordered_map<int, std::unordered_map<int, int>> sets;
        for (int i = 0; i < n; i++) {
            sets[find(i)][source[i]]++;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int par = find(i);
            auto& freq = sets[par];
            if (freq.count(target[i]) && freq[target[i]] > 0) {
                freq[target[i]]--;
            } else {
                res++;
            }
        }

        return res;
    }
};