class LUPrefix {
private:
    std::vector<bool> videos;
    int ptr = 1;

public:
    LUPrefix(int n) {
        videos = std::vector<bool>(n+1);
    }
    
    void upload(int video) {
        videos[video] = true;
        while (ptr < videos.size() && videos[ptr]) {
            ptr++;
        }
    }
    
    int longest() {
        return ptr-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */