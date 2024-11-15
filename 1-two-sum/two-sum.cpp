class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> ss;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++ ){
            ss.insert({nums[i],i});
        }
        for(int i = 0; i < nums.size(); i++ ){
            int num = nums[i];
            int rem = target - num;
            if(ss.count(rem) != 0){
                int index = ss[rem]; 
                if(index == i) continue;
                res.push_back(i);
                res.push_back(ss[rem]);
                break;
            }
        }
     return res;   
    }
};