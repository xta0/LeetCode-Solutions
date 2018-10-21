#include <iostream>
#include <vector>
#include <string>
using namespace std;

//O(n)
class Solution
{
  public:
    int search(vector<int> &arr, int key)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }
            //开始二分查找，target 可能在mid左边，也可能在mid右边
            else if (key < arr[mid])
            {
                //target 在mid右边的情况是 : 4 5 6 7(mid) 0(target) 1 2 3
                if (key < arr[l] && arr[mid] >= arr[l])
                {
                    l = mid + 1;
                }
                else
                {
                    //target 在mid左边
                    r = mid - 1;
                }
            }
            else
            {
                //target > mid
                //target 在mid左边的情况 8 9（target） 0(mid) 1 2
                if (key > arr[r] && arr[mid] <= arr[r])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main()
{

    vector<int> v = {1, 3};
    Solution s;
    s.search(v, 1);

    return 0;
}
