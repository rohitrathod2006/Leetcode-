class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mn = nums[0];
        int moves = 0;

        for (int num : nums) {
            moves += num - mn;
        }
        return moves;
    }
};