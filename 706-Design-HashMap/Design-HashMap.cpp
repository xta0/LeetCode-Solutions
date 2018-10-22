#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

struct HashNode{
    int key = -1;
    int value = -1;
    bool operator== ( const HashNode &n2) {
        return  key==n2.key;
    }
    
};
class MyHashMap {
    vector<list<HashNode>> _map;
    int sz = 100;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        _map = vector<list<HashNode>>(sz,list<HashNode>());
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = std::hash<int>()(key) % sz;
        list<HashNode>& l = _map[index];
        HashNode n = {key,value};
        auto itor = std::find(l.begin(),l.end(),n);
        if( itor == l.end()){
            l.push_back({key,value});
        }else{
            //same key, override
            itor->value = value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = std::hash<int>()(key) % sz;
        list<HashNode>& l = _map[index];
        if(!l.size()){
            return -1;
        }
        if(l.size()==1){
            return l.front().value;
        }
        auto itor = l.begin();
        while(itor!=l.end()){
            HashNode& node = *itor;
            if(node.key == key){
                return node.value;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = std::hash<int>{}(key) % sz;
        list<HashNode>& l = _map[index];
        l.clear();
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

//    ["MyHashMap","put","put","get","get","put","get", "remove", "get"]
//    [[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]r
int main(){
    
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout<<hashMap.get(1)<<endl;
    cout<<hashMap.get(3)<<endl;
    hashMap.put(2, 1);
    cout<<hashMap.get(2)<<endl;
    hashMap.remove(2);
    cout<<hashMap.get(2)<<endl;

    return 0;
}

