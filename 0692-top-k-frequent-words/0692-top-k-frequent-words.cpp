
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        int n = words.size();

        vector<vector<string>> bucket(n + 1);

        for (auto it : mp) {
            bucket[it.second].push_back(it.first);
        }

        vector<string> ans;

        for (int i = n; i >= 1; i--) {

            if (!bucket[i].empty()) {

                sort(bucket[i].begin(), bucket[i].end());

                for (string word : bucket[i]) {

                    ans.push_back(word);

                    if (ans.size() == k) {
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
