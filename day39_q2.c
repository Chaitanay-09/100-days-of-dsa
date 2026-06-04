#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        // Count frequency
        for(int n : nums)
            freq[n]++;

        // Max heap (frequency, number)
        priority_queue<pair<int,int>> pq;

        for(auto x : freq)
            pq.push({x.second, x.first});

        vector<int> ans;

        // Take top k frequent elements
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};