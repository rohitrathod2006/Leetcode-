class Solution {
public:
    int maximumValue(vector<string>& strs) {

        int ans = 0;

        for (string s : strs) {

            int val;

            bool isNumber = all_of(
                s.begin(),
                s.end(),
                [](char ch) {
                    return isdigit(ch);
                }
            );

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