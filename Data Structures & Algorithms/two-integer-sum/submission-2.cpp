class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_to_index;
        for (int i = 0; i < nums.size(); i++) {
            nums_to_index.push_back({nums[i], i});
        }

        sort(nums_to_index.begin(), nums_to_index.end());

        int begin_ptr = 0;
        int end_ptr = nums.size() - 1;

        while (begin_ptr < end_ptr) {
            int sum = nums_to_index[begin_ptr].first + nums_to_index[end_ptr].first;
            if (sum == target) {
                int first_index = nums_to_index[begin_ptr].second;
                int second_index = nums_to_index[end_ptr].second;
                return {min(first_index, second_index), max(first_index, second_index)};
            } else if (sum < target) {
                begin_ptr++;
            } else {
                end_ptr--;
            }
        }
        return {-1, -1};
    }
};
