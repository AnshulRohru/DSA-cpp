class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int chk = (nums.size()+1)/2;
        for(auto x:mp){
            if(x.second>=chk) return x.first;
        }
        return 0;
    }
};