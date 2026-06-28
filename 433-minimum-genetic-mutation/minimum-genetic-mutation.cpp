class Solution {
public:
    bool valid(std::string& a, std::string& b) {
        bool found = false;
        for (int i = 0; i < 8; i++) {
            if (a[i] != b[i]) {
                if (found)
                    return false;
                found = true;
            }
        }
        return true;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        const int n = bank.size();
        std::unordered_map<std::string, bool> memo;
        std::queue<std::string> q;
        q.push(startGene);
        memo[startGene] = true;

        int res = 0;
        while (!q.empty()) {
            size_t s = q.size();
            for (int i = 0; i < s; i++) {
                std::string& str = q.front();
                q.pop();
                if (str == endGene)
                    return res;
                
                for (auto& gene : bank) {
                    if (memo.find(gene) == memo.end() && valid(gene, str)) {
                        q.push(gene);
                        memo[gene] = true;
                    }
                }
            }
            res++;
        }

        return -1;
    }
};