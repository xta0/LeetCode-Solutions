#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyHashSet {
private:
    int sz = 1000001;
    vector<int> arr;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        arr = vector<int>(sz,-1);
    }
    
    void add(int key) {
        int index=key%sz;
        arr[index]=key;
    }
    
    void remove(int key) {
        int index = key%sz;
        arr[index] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key%sz;
        return arr[index] != -1;
    }
};

int main(){




    return 0;
}