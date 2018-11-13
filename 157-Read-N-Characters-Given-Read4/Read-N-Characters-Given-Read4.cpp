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

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {

        int ans = 0;int lastRead=0;
        while(true){
            lastRead = read4(buf);
            ans+=lastRead;
            if(lastRead < 4){
                break;
            }
            buf+=4;
        }
        return min(ans,n);
    }
};


int main(){




    return 0;
}