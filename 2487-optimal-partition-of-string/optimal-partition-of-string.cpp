class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        int res = 1;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
            if(mp[s[i]]>1){
                res++;
                mp.clear();
                mp[s[i]]++;
            }
        }
        return res;
    }
};