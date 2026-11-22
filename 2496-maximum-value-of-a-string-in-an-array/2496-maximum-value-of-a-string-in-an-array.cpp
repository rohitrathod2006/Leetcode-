class Solution {
public:
    int maximumValue(vector<string>& strs) {

        int ans = 0;

        for (string s : strs) {

            bool isNumber = true;

            for (char ch : s) {
                if (!isdigit(ch)) {
                    isNumber = false;
                    break;
                }
            }

            int val;

            if (isNumber) {
                val = stoi(s);
            }
            else {
                val = s.length();
            }
            ans = max(ans, val);
        }
        return ans;
    }
};