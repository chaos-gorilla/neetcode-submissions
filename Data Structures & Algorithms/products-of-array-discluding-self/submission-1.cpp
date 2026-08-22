class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = int(nums.size());
        const int total_elements = n;

        vector<int> prefix_product(n);
        vector<int> suffix_product(n);

        prefix_product[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            prefix_product[i] = prefix_product[i - 1] * nums[i - 1];
        }
        suffix_product[total_elements - 1] = 1;
        for (int i = total_elements - 2; i >= 0; i--) {
            suffix_product[i] = suffix_product[i + 1] * nums[i + 1];
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = prefix_product[i] * suffix_product[i];
        }
        return result;
    }
};
