#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

typedef list<int>::iterator itor;
class LRUCache {
private:
    list<int> _list;
    unordered_map<int, pair<int,itor>> _cache;
    int _size = 0;
public:
    LRUCache(int capacity) {
        _size = capacity;
    }
    int get(int key) {

        if(cache.find(key) != cache.end()){
            return cache[key];
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(_cache.find(key) != _cache.end()){
            _list.push_front(value);
            _cache[key] = _list.begin();
        }
    }
};

int main(){




    return 0;
}