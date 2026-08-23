class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int len = int(nums.size());

        vector<int> result(len, 1);

        int prefix_prod = 1;
        for (int i = 0; i < len; i++) {
            result[i] = prefix_prod;
            prefix_prod *= nums[i];
        }

        int suffix_prod = 1;
        for (int i = len - 1; i >= 0; i--) {
            result[i] *= suffix_prod;
            suffix_prod *= nums[i];
        }

        return result;
    }
};
