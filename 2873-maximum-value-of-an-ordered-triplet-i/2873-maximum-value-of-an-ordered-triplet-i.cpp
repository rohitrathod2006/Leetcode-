
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMax(n);
        suffixMax[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(nums[i], suffixMax[i + 1]);
        }

        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {

                long long diff = nums[i] - nums[j];
                long long value = diff * suffixMax[j + 1];

                ans = max(ans, value);
            }
        }
        return ans;
    }
};
