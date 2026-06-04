class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<nums.size();i++)
        {
            // remove elements outside window
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();

            // remove smaller elements
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // push current index
            dq.push_back(i);

            // store result
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};