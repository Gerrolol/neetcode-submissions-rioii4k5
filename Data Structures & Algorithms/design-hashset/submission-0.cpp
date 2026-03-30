class MyHashSet {
public:
    int temp[1000000] = {0};

    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key)){
            temp[key] = 1;
        }
    }
    
    void remove(int key) {
        temp[key] = 0;
    }
    
    bool contains(int key) {
        if(temp[key] == 0){
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */