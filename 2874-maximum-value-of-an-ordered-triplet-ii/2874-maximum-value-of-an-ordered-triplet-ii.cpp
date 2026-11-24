class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        long long ans = 0;
        long long maxNum = 0;
        long long maxDiff = 0;

        for (int num : nums) {

            ans = max(ans, maxDiff * num);

            maxDiff = max(maxDiff, maxNum - num);

            maxNum = max(maxNum, (long long)num);
        }
        return ans;
    }
};