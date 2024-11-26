class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
       vector<int> vec(n,0);
       for(int i = 0 ; i < edges.size() ; i++){
            vec[edges[i][1]]++;
       }
       int cnt = 0;
       int res = 0;
       for(int i = 0 ; i < n ; i++){
        if(vec[i] == 0){
            cnt++;
            res = i;
        }
       }
       return cnt==1 ? res : -1;
    }
};