class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (string str : arr) {
            string lexo = str;
            sort(lexo.begin(), lexo.end());
            mp[lexo].push_back(str);
        }
        for (auto x : mp) ans.push_back(x.second);
        return ans;
    }
};