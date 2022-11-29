class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end()){ // ele present 
            return false;
        }
        else{
            st.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(st.find(val)!=st.end()){ // item present in set
            st.erase(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        // int num = rand() % st.size();
        // auto itr = st.begin() + num;
        int sz = rand() % st.size();
        auto itr = st.begin();
        auto it = std::begin(st);
        // 'advance' the iterator n times
        std::advance(it,sz);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */