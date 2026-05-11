class Trie {
public:
    typedef struct Node {
        char value = '\0';
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
    }
    
    void insert(const std::string_view word) {
        Node* x = parent;
        for (int i = 0; i < word.size(); i++) {
            int j = word[i]-'a';
            if (x->children[j] == nullptr)
                x->children[j] = new Node(j);
            x = x->children[j];
        }
        x->isEnd = true;
    }
    
    bool search(const std::string_view word) {
        size_t size = word.size();
        Node* x = parent;

        for (int i = 0; i < size; i++) {
            int j = word[i]-'a';

            if (x->children[j] == nullptr)
                return false;
            x = x->children[j];
        }

        return x->isEnd;
    }
    
    bool startsWith(const std::string_view word) {
        size_t size = word.size();
        Node* x = parent;

        for (int i = 0; i < size; i++) {
            int j = word[i]-'a';

            if (x->children[j] == nullptr)
                return false;
            x = x->children[j];
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