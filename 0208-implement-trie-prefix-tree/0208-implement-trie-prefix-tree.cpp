class Trie {
private:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new Node();
            }

            current = current->children[index];
        }

        current->isEnd = true;
    }

    bool search(string word) {
        Node* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->children[index] == nullptr) {
                return false;
            }

            current = current->children[index];
        }

        return current->isEnd;
    }

    bool startsWith(string prefix) {
        Node* current = root;

        for (char c : prefix) {
            int index = c - 'a';

            if (current->children[index] == nullptr) {
                return false;
            }

            current = current->children[index];
        }

        return true;
    }
};