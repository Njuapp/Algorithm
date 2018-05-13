class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res;
        unordered_map<int,pair<int,string>> mp;
        for(int i = 0; i < indexes.size(); i++){
            if(S.substr(indexes[i], sources[i].length()) == sources[i]){
                mp[indexes[i]] = make_pair(sources[i].length(), targets[i]);
            }
        }
        int i = 0;
        while(i < S.length()){
            if(mp.find(i) != mp.end()){
                res += mp[i].second;
                i += mp[i].first;
            }
            else{
                res += S[i];
                i++;
            }
        }
        return res;
    }
};