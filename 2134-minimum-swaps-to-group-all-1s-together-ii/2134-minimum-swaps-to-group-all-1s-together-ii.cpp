class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);

        if (k == 0 || k == n) return 0;

        vector<int> arr(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            arr[i] = nums[i % n];
        }
        int ones = 0;

        for (int i = 0; i < k; i++) {
            ones += arr[i];
        }
        int maxOnes = ones;

        for (int i = k; i < n + k - 1; i++) {
            ones += arr[i];
            ones -= arr[i - k];

            maxOnes = max(maxOnes, ones);
        }
        return k - maxOnes;
    }
};