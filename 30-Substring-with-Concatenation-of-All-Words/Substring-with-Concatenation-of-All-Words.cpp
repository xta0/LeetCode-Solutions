#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    string val;
    vector<TreeNode* >* children;
    TreeNode(string str):val(str){
        children = new vector<TreeNode* >();
    }
};
class Solution {
private:
    void buildTree(TreeNode* root, vector<string>vec){
        vector<string> tmp(vec);
        auto itor = std::find(tmp.begin(), tmp.end(), root->val);
        tmp.erase(itor);
 
        // tmp.erase()
        for(auto word:tmp){
            TreeNode* node = new TreeNode(word);
            root->children->push_back(node);
        }
        for(auto child: *root->children){
            buildTree(child, tmp);
        }
    }
    void traverse(TreeNode* root, string& code, vector<string>& codes){
        
        string str = root -> val;
        code += str;
        if(root->children->size() > 0){
            for(auto child: *root->children){
                traverse(child,code,codes);
                code.erase(code.length()-str.length(),str.length());
            }
            
        }else{
            //cout<<code<<endl;
            codes.push_back(code);
        }
    }
    void logTree(TreeNode* node){
        queue<TreeNode* > q;
        q.push(node);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            cout<<front->val<<" ";
            for(auto child: *front->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<TreeNode* >forest;
        for(auto word :words){
            TreeNode* root = new TreeNode(word);
            buildTree(root, words);
            logTree(root);
            forest.push_back(root);
        }
        
        vector<string> results;
        for(auto tree : forest){
            vector<string> codes = {};
            string code = "";
            traverse(tree,code,codes);
            results.insert(results.end(),codes.begin(),codes.end());
        }

        set<int> ret;
        for(auto code : results){
            size_t pos = s.find(code,0);
            while(pos != string::npos){
                ret.insert((int)pos);
                pos = s.find(code,pos+1);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    
    }
};

int main(){
    
    Solution s;
    
 vector<string> words = {"a","b","c","d","a","b","c","d"};
//    vector<string> words = {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
    vector<int> ret = s.findSubstring("pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel",words);
//    vector<int> ret = s.findSubstring("barfoofoobarthefoobarman",words);
//    vector<string> words = {"word","good","best","good"};
//    vector<int> ret = s.findSubstring("wordgoodgoodgoodbestword",words);
//    vector<string> words = {"foo","bar"};
//    vector<int> ret = s.findSubstring("foobarfoobar",words);


    for(auto n : ret){
        cout<<n<<endl;
    }
    
    
    return 0;
}
