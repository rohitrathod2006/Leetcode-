
class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);

        if (k == 0 || k == n) {
            return 0;
        }
        int ones = 0;

        for (int i = 0; i < k; i++) {
            ones += nums[i];
        }
        int maxOnes = ones;

        for (int i = k; i < n + k; i++) {

            ones += nums[i % n];
            ones -= nums[(i - k) % n];

            maxOnes = max(maxOnes, ones);
        }
        return k - maxOnes;
    }
};
