class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mappings;
        for (string &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mappings[key].push_back(s);
        }
        vector<vector<string>> results;
        for (auto &[k, v] : mappings) {
            results.emplace_back(v);
        }
        return results;
    }
};
