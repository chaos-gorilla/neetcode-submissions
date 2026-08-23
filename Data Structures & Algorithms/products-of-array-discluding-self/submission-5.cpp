class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int len = int(nums.size());
        vector<int> prefix_prod(nums.size(), 1);
        vector<int> suffix_prod(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            prefix_prod[i] = prefix_prod[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix_prod[i] = suffix_prod[i + 1] * nums[i + 1];
        }

        vector<int> answer(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            answer[i] = prefix_prod[i] * suffix_prod[i];
        }
        return answer;
    }
};
