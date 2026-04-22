class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        std::vector<std::string> res = {};

        for (std::string& query : queries) {
            for (std::string& w : dictionary) {
                int a = 0;

                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != w[i]) {
                        a++;
                    }
                }        
                    
                if (a <= 2) {
                    res.push_back(query);
                    break;
                }
            }
        }

        return res;
    }
};