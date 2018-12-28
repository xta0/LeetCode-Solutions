#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 Solution: Sweep Line
 DS: Balanced BST (set / multiset)
 
 1. 定义结构 Points{L,height,type}, type=1:entering，type=-1 leaving
 2. 创建数组，vector<Points>, X轴上所有点排序
 3. 从左到右沿x轴扫描，两种情况
 - 如果是进入点，则找大楼最高的点，放入结果中，同时放入set中
 - 如果是离开点，检查set中的最大值，如果该点是最大值，从set中移除该点，将set中的最大值放入结果中
 4. 考虑三个edge case
 - 两个大楼有相同的enteringPoint
 - 两个大楼有相同的leavingPoint
 - 一个大楼的entering point和另一个大楼的leaving point相同
 */
class Solution {
    struct PT{
        int x;
        int h;
        int type;
    };
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<PT> points;
        for(auto &v : buildings){
            //进入点
            points.push_back({v[0],v[2],1});
            //离开点
            points.push_back({v[1],v[2],-1});
        }
        // auto func = [&]()
        std::sort(points.begin(),points.end(),[&](const PT& pt1, const PT& pt2){
            //需要考虑三种edge cases:
            if(pt1.x == pt2.x){
                //entering point相同，高的排前面
                if(pt1.type == 1 && pt2.type == 1){
                    return pt1.h > pt2.h;
                }
                //entering point排在前面
                if(pt1.type== -1 && pt2.type == 1){
                    return false;
                }
                //entering point排在前面
                if(pt1.type== 1 && pt2.type == -1 ){
                    return true;
                }
                //leaving point相同，矮的排前面
                if(pt1.type == -1 && pt2.type == -1){
                    return pt1.h < pt2.h;
                }
            }
            return pt1.x < pt2.x;
        });
        
        
        multiset<int> st = {0};
        
        vector<pair<int,int>> keyPoints;
        for(auto &pt : points){
            cout<<"{"<<pt.x<<","<<pt.h<<"}"<<endl;
       
            if(pt.type == 1){
                //last element in the set has the largest value
                int maxHeight = st.empty()?0:*st.rbegin();
                if(pt.h > maxHeight){
                    keyPoints.push_back({pt.x,pt.h});
                }
                st.insert(pt.h);
            }else{
                st.erase(st.equal_range(pt.h).first);
                int maxHeight = st.empty()?0:*st.rbegin();
                if(pt.h > maxHeight){
                    keyPoints.push_back({pt.x,maxHeight});
                }
            }
        }
        return keyPoints;
        
    }
};

int main(){
    
    vector<vector<int>> buildings = {{2,9,10},{9,12,15}};
    Solution s;
    auto ret = s.getSkyline(buildings);
    for(auto &p : ret){
        cout<<"["<<p.first<<","<<p.second<<"]"<<endl;
    }
    
    
    return 0;
}
