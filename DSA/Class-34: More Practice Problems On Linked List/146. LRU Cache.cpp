struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> dict;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
   
    int get(int key) {
        if ( dict.find(key) == dict.end() ) return -1;
        Node* cur = dict[key];
        remove(cur);
        add(cur);
        return cur->val;
    }
   
    void put(int key, int value) {
        Node* cur = new Node(key, value);
        if (dict.find(key) != dict.end()) {
            cur = dict[key];
            cur->val = value;
            remove(cur);
        }

        dict[key] = cur;
        add(cur);

        if(dict.size() > capacity) {
            Node* deleteNode = head->next;
            remove(deleteNode);
            dict.erase(deleteNode->key);
        }
    }

    void add(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        tail->prev = node;

        node->next = tail;
        node->prev = prev;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
