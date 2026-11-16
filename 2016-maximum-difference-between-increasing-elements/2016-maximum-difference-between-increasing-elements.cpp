
class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixMin(n);
        prefixMin[0] = nums[0];

        for (int i = 1; i < n; i++) {

            prefixMin[i] = min(prefixMin[i - 1], nums[i]);

        }

        int ans = -1;

        for (int j = 1; j < n; j++) {

            if (nums[j] > prefixMin[j - 1]) {

                ans = max(ans, nums[j] - prefixMin[j - 1]);

            }
        }
        return ans;
    }
};
