class Solution {
public:
    string entityParser(string text) {
        std::string res = "";
        const int n = text.size();
        std::unordered_map<std::string, std::string> replace = {
            {"&quot;", "\""},
            {"&apos;", "\'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"},
        };
        for (int i = 0; i < n; i++) {
            if (text[i] != '&') {
                res += text[i];
                continue;
            }
            std::string key = "";
            key += text[i];
            for (++i; i < n && text[i] != ';' && text[i] != '&'; i++)
                key += text[i];
            if (i < n && text[i] == ';')
                key += text[i];
            std::string val = replace[key].empty() ? key : replace[key]; 
            i -= text[i] == '&';
            res += val;
        }
        return res;
    }
};