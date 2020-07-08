class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int target=-nums[i];
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                if(nums[start]+nums[end]<target){
                    start++;
                }
                else if(nums[start]+nums[end]>target){
                    end--;
                }
                else{
                    vector<int>temp;
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    temp.push_back(nums[i]);
                    ans.push_back(temp);
                    while(start<end && nums[start]==temp[0]){
                        start++;
                    }
                    while(start<end && nums[end]==temp[1]){
                        end--;
                    }
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};
