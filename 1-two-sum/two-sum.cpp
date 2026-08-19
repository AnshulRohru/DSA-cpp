class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> mp;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
       }
       for(int i=0;i<nums.size();i++){
        int x = target - nums[i];
        if(mp.find(x)!=mp.end() && (x!=nums[i]||mp[x]>1)){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==x){
                    return {i,j};
                }
            }
        }
       }
       return {};
    }
};