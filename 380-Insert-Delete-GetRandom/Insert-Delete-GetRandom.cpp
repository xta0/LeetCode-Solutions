#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/*
Solution: Hashmap+Array
Time:O(1)
Space:O(n)
*/
class RandomizedSet {
    //key: val, value: index
    unordered_map<int,int> umap;
    vector<int> arr;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /*
    插入元素在数组末尾
    */
    bool insert(int val) {
        if(umap.count(val)){
            return false;
        }
        arr.push_back(val);
        umap[val] = arr.size();
        return true;
    }
    
    /*
    删除操作将：
    1.待删除的元素和末尾元素交换
    2.更新末尾元素的index为待删除元素的index
    3.删除末尾元素
    */
    bool remove(int val) {
        if(!umap.count(val)){
            return false;
        }
        //待删除元素的index
        int index = umap[val];
        umap[arr.back()] = index;
        //从hashmap中删除
        umap.erase(val);
        //将index位置更新成最后一个元素
        swap(arr[index],arr.back());
        //删除最后一个元素
        arr.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int index=rand()%arr.size();
        return arr[index];
    }
};

int main(){




    return 0;
}