// THIS IS THE WORST PROBLEM I HAVE EVER SEEN IN MY LIFE
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        std::unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) 
            count[i]++;
        
        for (auto i : count) 
            res = __gcd(i.second, res);
        
        return res > 1;
    }
};