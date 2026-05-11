class Trie {
public:
    typedef struct Node {
        char value;
        bool isEnd = false;
        Node* children[26];

        Node() {
            for (int i = 0; i < 26; i++) { 
                this->children[i] = nullptr;
            }
        }

        Node(char v) {
            this->value = v;
            for (int i = 0; i < 26; i++) { 
                this->children[i] = nullptr;
            }
        }
    } Node;

    Node* parent;

    Trie() {
        parent = new Node();
        parent->value = '\0';
        for (int i = 0; i < 26; i++) 
            parent->children[i] = nullptr;
    }
    
    void insert(string word) {
        Node* x = parent;
        for (int i = 0; i < word.size(); i++) {
            if (x->children[word[i]-'a'] == nullptr)
                x->children[word[i]-'a'] = new Node(word[i]-'a');
            x = x->children[word[i]-'a'];
        }
        x->isEnd = true;
    }
    
    bool search(string word) {
        size_t size = word.size();
        Node* x = parent;

        for (int i = 0; i < size; i++) {
            if (x->children[word[i]-'a'] == nullptr)
                return false;
            x = x->children[word[i]-'a'];
        }

        return x->isEnd;
    }
    
    bool startsWith(std::string word) {
        size_t size = word.size();
        Node* x = parent;

        for (int i = 0; i < size; i++) {
            if (x->children[word[i]-'a'] == nullptr)
                return false;
            x = x->children[word[i]-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */