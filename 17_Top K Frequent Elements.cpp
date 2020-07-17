class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto sub:mp){
            pair<int,int> p=make_pair(sub.second,sub.first);
            pq.push(p);
        }
        while(!pq.empty() && k--){
            pair<int,int>pp=pq.top();
            ans.push_back(pp.second);
            pq.pop();
        }
        return ans;
    }
};
