class MyHashMap {
public:
    std::unordered_map<int, int> map;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if (value == 0)
            map[key] = -1;
        else 
            map[key] = value;
    }
    
    int get(int key) {
        if (map[key] == -1)
            return 0;
        if (map[key] == 0)
            return -1;
        return map[key];
    }
    
    void remove(int key) {
        map[key] = 0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */