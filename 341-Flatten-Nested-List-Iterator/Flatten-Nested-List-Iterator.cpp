#include <iostream>
#include <vector>
#include <string>
using namespace std;


class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    int getInteger() const;

    const vector<NestedInteger> &getList() const;
};
 
//递归
class NestedIterator {
    vector<int> arr;
    int index=0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        arr = flatten(nestedList);
    }

    int next() {
        return arr[index++];
    }

    bool hasNext() {
        return index<arr.size();
    }
private:
    vector<int> flatten(vector<NestedInteger>& arr){
        vector<int> ret;
        for(int i=0;i<arr.size();i++){
            NestedInteger& ni = arr[i];
            if(ni.isInteger()){
                ret.push_back(ni.getInteger());
            }else{
                auto x = flatten(ni.getList());
                ret.insert(ret.end(),x.begin(),x.end());
            }
        }
        return ret;
    }
};

int main(){




    return 0;
}