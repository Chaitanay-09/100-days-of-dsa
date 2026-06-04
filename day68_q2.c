class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        for (auto &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }

            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }

        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        string result;

        while (!q.empty()) {
            char node = q.front();
            q.pop();
            result += node;

            for (char nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (result.size() != indegree.size()) {
            return "";
        }

        return result;
    }
};