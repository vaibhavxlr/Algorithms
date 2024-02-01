class MyHashMap {
private:
    vector<int> HashMap;
public:
    MyHashMap() {
        HashMap = vector<int>(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        HashMap[key] = value;
    }
    
    int get(int key) {
        return HashMap[key];
    }
    
    void remove(int key) {
        HashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */