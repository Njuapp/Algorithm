class Solution {
    vector<string> vecs;
    int target;
public:
    vector<string> addOperators(string num, int target) {
        this->target = target;
        add(0, num, "", 1, 0);
        return vecs;
    }
    void add(int pos, string num, string now, long long res, long long multi){
        if(pos == num.length()){
            if(res == target){
                vecs.push_back(now);
                return;
            }
        }
        for(int i = pos; i < num.length(); i++){
            if(i != pos && num[pos] == '0') break;
            long long cur = stoll(num.substr(pos, i - pos + 1));
            if(pos == 0){
                add(i+1, num, num.substr(pos, i - pos + 1), cur, cur);
                continue;
            }
            add(i+1, num, now + "+" + num.substr(pos, i - pos + 1), res + cur, cur);
            add(i+1, num, now + "-" + num.substr(pos, i - pos + 1), res - cur, -cur);
            add(i+1, num, now + "*" + num.substr(pos, i - pos + 1), res  - multi + multi * cur, multi * cur);
        }
    }
};
