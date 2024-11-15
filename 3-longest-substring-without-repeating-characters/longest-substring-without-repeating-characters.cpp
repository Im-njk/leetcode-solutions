class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        
        map<char, int> mp;
        int l = 0, r = 0;
        int len = 0;
        while (r<s.size() && l<s.size())
        {
            mp[s[r]]++;
            if(mp[s[r]]>1){
                while(mp[s[r]]>1){
                    mp[s[l]]--;
                    l++;
                }
            }
            len = max(len, r-l+1);
            r++;
        }
        return len;         
    }
};