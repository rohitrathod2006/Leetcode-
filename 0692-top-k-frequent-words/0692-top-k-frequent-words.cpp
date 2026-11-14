
class Solution {
public:
    struct Compare {
        unordered_map<string, int>* freq;

        Compare(unordered_map<string, int>* f) {
            freq = f;
        }

        bool operator()(string a, string b) {

            if ((*freq)[a] == (*freq)[b]) {
                return a < b;
            }
            return (*freq)[a] > (*freq)[b];
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        priority_queue<string, vector<string>, Compare>
            pq((Compare(&mp)));

        for (auto it : mp) {

            pq.push(it.first);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
