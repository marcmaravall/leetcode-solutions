class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        std::vector<std::vector<int>> res;
        std::unordered_map<int, int> weights;
        
        for (auto& item : items1) weights[item[0]] += item[1];
        for (auto& item : items2) weights[item[0]] += item[1];
        
        for (auto& pair : weights) {
            res.push_back({pair.first, pair.second});
        }

        std::sort(res.begin(), res.end());
        return res;
    }
};