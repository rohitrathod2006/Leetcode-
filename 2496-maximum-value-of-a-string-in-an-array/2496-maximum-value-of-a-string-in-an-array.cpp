class Solution {
public:
    int maximumValue(vector<string>& strs) {

        int ans = 0;

        for (string s : strs) {

            int val = 0;
            bool isNumber = true;

            for (char ch : s) {

                if (ch >= '0' && ch <= '9') {

                    val = val * 10 + (ch - '0');

                }
                else {

                    isNumber = false;
                    break;

                }
            }

            if (!isNumber) {
                val = s.length();
            }
            ans = max(ans, val);
        }
        return ans;
    }
};