class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(auto s: strs){
            string temp=s;
            sort(s.begin(),s.end());
            mp[s].push_back(temp);
        }
        for(auto i:mp){
            res.push_back(i.second);
        }
        return res;
    }
};