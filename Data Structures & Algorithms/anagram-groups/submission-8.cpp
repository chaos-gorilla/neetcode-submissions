class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mps;
        for (string &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mps[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &p : mps) {
            res.push_back(p.second);
        }
        return res;
    }
};
