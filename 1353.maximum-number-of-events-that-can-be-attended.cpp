class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int count = 0;
        int index = 0;
        int day = 0;
        int n = events.size();

        while(!minHeap.empty()  || index < n) {
            if(minHeap.empty()) {
                day = events[index][0];
            }

            while(index < n && events[index][0] <= day) {
                minHeap.push(events[index][1]);
                index++;
            }
            minHeap.pop();
            count++;
            day++;

            while(!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }

        return count;

        return count;
    }
};