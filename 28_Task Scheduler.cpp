// The most frequent character will be placed at (n+1)th distance from each other, such that the gap between them remains 'n'. So, max_freq will count the maximum occurence of the character. Finally, minimum time idle_time will be (max_freq-1)*(n+1)+1, +1 because at the last occurence of the element we must stop, This minimum required time can be extended if there are same number of maximum frequency elements in the character array,here, denoted by inc, so +1 for all such elements. Now, if the other char does not fit in this time we must consider the complete tasks.size().


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) 
            return (int)tasks.size();
        map<char,int> freq; 
        int max_freq = 0,inc=0;
        for(int x : tasks) {
            freq[x]++;
            max_freq = max(max_freq, freq[x]);
        }
        int idle_time = (max_freq-1)*(n+1)+1;
        for(auto it: freq){
            if(it.second==max_freq) 
                inc++;
        }
        int ans = idle_time+(inc-1); // One of which was already used for the maximum frequency char earlier //
        return max(ans, (int)tasks.size());
    }
};
