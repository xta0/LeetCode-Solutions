#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;


class LRUCache {
private:
    //每个节点的索引
    unordered_map<int, list<pair<int,int>>::iterator> indexes;
    //每个节点是k,v pair
    list<pair<int,int>> lst;
    int sz;
    
public:
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        int ans = -1;
        if(indexes.find(key) != indexes.end()){
            auto itor = indexes[key];
            ans = itor->second;
            //update tail elements
            lst.erase(itor);
            lst.push_front(*itor);
            //update new index
            indexes[key] = lst.begin();
        }
        return ans;
    }
    
    void put(int key, int value) {
        if(indexes.find(key) != indexes.end()){
            //存在key
            //删除旧索引和list中的元素
            auto itor = indexes[key];
            lst.erase(itor);
            indexes.erase(key);
        }else{
            //new element
            //check capacity
            if(lst.size() >= sz){
                auto p = lst.back();
                lst.pop_back();
                //remove indexes
                indexes.erase(p.first);
            }
        }
        //update list
        lst.push_front({key,value});
        //update indexes
        indexes[key] = lst.begin();
        
    }
};


int main(){
//    ["LRUCache","put","put","get","put","get","put","get","get","get"]
//    [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;
    cache.put(3, 3);
    cout<<cache.get(2)<<endl;
    cache.put(4, 4);
    cout<<cache.get(1)<<endl;
    cout<<cache.get(3)<<endl;
    cout<<cache.get(4)<<endl;
}
