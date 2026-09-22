class OrderedStream {
private:
    std::unordered_map<int, std::string> map;
    int ptr = 1;

public:
    OrderedStream(int n) {
        
    }
    
    vector<string> insert(int idKey, string value) {
        map[idKey] = value;
        std::vector<std::string> res;
        while (map.contains(ptr)) {
            res.push_back(map[ptr++]);
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */