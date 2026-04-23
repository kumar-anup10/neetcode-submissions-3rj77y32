class Solution {
public: 
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int sum,int index,int target)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return ;
        }
        if(sum>target || index==nums.size())
        return;
        solve(nums,ans,temp,sum,index+1,target);
        temp.push_back(nums[index]);
        solve(nums,ans,temp,sum+nums[index],index,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,ans,temp,0,0,target);
        return ans;
    }
};
