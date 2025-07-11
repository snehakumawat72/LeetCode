class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());
        
        // Priority queue for available rooms (min-heap by room number)
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        
        // Priority queue for busy rooms (min-heap by end time, then room number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        
        // Initialize all rooms as available
        for (int i = 0; i < n; i++) {
            availableRooms.push(i);
        }
        
        // Count meetings per room
        vector<int> meetingCount(n, 0);
        
        for (auto& meeting : meetings) {
            long long startTime = meeting[0];
            long long endTime = meeting[1];
            long long duration = endTime - startTime;
            
            // Free up rooms that have finished by current start time
            while (!busyRooms.empty() && busyRooms.top().first <= startTime) {
                availableRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            
            if (!availableRooms.empty()) {
                // Assign to available room with lowest number
                int room = availableRooms.top();
                availableRooms.pop();
                meetingCount[room]++;
                busyRooms.push({endTime, room});
            } else {
                // All rooms busy, delay meeting
                // Find the room that becomes available earliest
                auto earliestRoom = busyRooms.top();
                busyRooms.pop();
                
                long long earliestEndTime = earliestRoom.first;
                int room = earliestRoom.second;
                
                meetingCount[room]++;
                // Schedule delayed meeting to start when room becomes available
                busyRooms.push({earliestEndTime + duration, room});
            }
        }
        
        // Find room with most meetings (lowest number if tied)
        int maxMeetings = 0;
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                result = i;
            }
        }
        
        return result;
    }
};