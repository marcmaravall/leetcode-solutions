class OrderedStream {
private:
    std::vector<std::string> stream;
    int ptr = 1;

public:
    OrderedStream(int n) {
        stream = std::vector<std::string>(n+1);
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        std::vector<std::string> res;
        while (ptr < stream.size() && !stream[ptr].empty()) {
            res.push_back(stream[ptr++]);
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */