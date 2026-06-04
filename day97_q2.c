class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int rooms = 0, maxRooms = 0;
        int i = 0, j = 0;
        
        while (i < n) {
            if (start[i] < end[j]) {
                // New meeting starts before earliest ending → need new room
                rooms++;
                i++;
            } else {
                // start[i] >= end[j] → a room is freed (same time is allowed)
                rooms--;
                j++;
            }
            maxRooms = max(maxRooms, rooms);
        }
        
        return maxRooms;
    }
};