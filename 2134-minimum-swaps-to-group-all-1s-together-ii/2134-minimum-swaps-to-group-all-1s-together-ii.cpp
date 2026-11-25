class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);

        if (k == 0 || k == n) return 0;

        vector<int> prefix(2 * n + 1, 0);

        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + nums[i % n];
        }
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int ones = prefix[i + k] - prefix[i];

            ans = min(ans, k - ones);
        }
        return ans;
    }
};