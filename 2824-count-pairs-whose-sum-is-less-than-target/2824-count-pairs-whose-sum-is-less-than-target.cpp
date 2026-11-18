
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n - 1; i++) {
            int pos = lower_bound(
                nums.begin() + i + 1,
                nums.end(),
                target - nums[i]
            ) - nums.begin();

            count += pos - (i + 1);
        }
        return count;
    }
};
