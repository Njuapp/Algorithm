//Author: Cheng Hang(calvinhance@gmail.com)
//Date: 2018-02-21 14:49:21
//Last modified: 2018-02-21 15:40:20
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class UnionFind{
    vector<int> root;
public:
    UnionFind(){
        for(int i = 0; i < 26; i++)
            root.push_back(-1);
    }
    void unite(char a, char b){
        root[rt(a-'a')]=rt(b-'a');
    }
    bool find(char a, char b){
        int idx1 = a-'a';
        int idx2 = b-'a';
        if(rt(idx1)!=rt(idx2))
            return false;
        else
            return true;
    }
    int rt(int cur){
       while(root[cur]!=-1){
           cur = root[cur];
       }
       return cur;
    }
    void print(){
        vector<vector<int> > equi;
        map<int, int> mp;
        for(int i = 0; i < 26; i++){
           // printf("%c ",root[i]+'a');
            
            if(root[i] == -1){
                vector<int> vec(1,i);
                equi.push_back(vec);
                mp[i] = equi.size()-1;
            }
        }
        for(int i = 0; i < 26; i++){
           if(root[i]!=-1){
               int ind = mp[rt(i)];
               //printf("%c root:%c\n",'a'+i, 'a'+rt(i));
               equi[ind].push_back(i);
           }
        }
        int sum = 0;
        for(int i = 0; i < equi.size(); i++){
            if(equi[i].size()==1)
                continue;
            else
                sum+= equi[i].size()-1;
        }
        cout<<sum<<endl;
        for(int i = 0; i < equi.size(); i++){
            for(int j = 0; j < equi[i].size()-1; j++){
                printf("%c %c\n",'a'+equi[i][j], 'a'+equi[i][j+1]);
            }
        }
    }
};
        
int main(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    UnionFind uf;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i])
            continue;
        if(uf.find(a[i],b[i]))
            continue;
        else
            uf.unite(a[i],b[i]);
    }
    uf.print(); 
    return 0;
}
