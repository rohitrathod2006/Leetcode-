class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int count1 = 0;
        int count2 = 0;

        for(int x : nums1) {
            if(binary_search(nums2.begin(), nums2.end(), x)) {
                count1++;
            }
        }
        for(int x : nums2) {
            if(binary_search(nums1.begin(), nums1.end(), x)) {
                count2++;
            }
        }
        return {count1, count2};
    }
};