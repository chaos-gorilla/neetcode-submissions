class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_pos_seen;

        if (s.empty()) {
            return 0;
        }

        int left = 0;
        int right = 0;
        last_pos_seen[s[left]] = 0;
        int biggest = 1;

        while (left <= right and right < s.size() - 1) {
            right++;
            char char_at_right = s[right];
            if (last_pos_seen.find(char_at_right) != last_pos_seen.end()) {
                left = max(left, last_pos_seen[char_at_right] + 1);
            }
            last_pos_seen[char_at_right] = right;
            biggest = max(biggest, (right - left + 1));
        }

        return biggest;
    }
};
