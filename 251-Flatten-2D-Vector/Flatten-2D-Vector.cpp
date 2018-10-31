#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Vector2D {
    int i=0;
    vector<int> array;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(int i=0;i<vec2d.size();i++){
            vector<int>& vec = vec2d[i];
            for(auto x:vec){
                array.push_back(x);
            }
        }
    }
    int next() {
        return array[i++];
    }

    bool hasNext() {
        if(!array.size()){
            return false;
        }
        if(i>=array.size()){
            return false;
        }
        return true;
    }
};
int main(){




    return 0;
}