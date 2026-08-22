class Solution {
public:
    unordered_map<int, int> precomputed;
    unordered_set<int> s;

    int recursiveFind(int e) {
        if (precomputed[e]) {
            return precomputed[e];
        } else {
            if (s.find(e) == s.end()) {
                precomputed[e] = 0;
                return precomputed[e];
            }
            precomputed[e] = 1 + recursiveFind(e + 1);
            return precomputed[e];
        }
    }

    int longestConsecutive(vector<int>& nums) {
        for (int e : nums) s.insert(e);
        int ans = 0;
        for (int e : nums) {
            ans = max(ans, recursiveFind(e));
        }
        return ans;
    }
};
