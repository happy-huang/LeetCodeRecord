class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty() or nums.size()<3) return {};
        vector<vector<int>> ans;

        int n = nums.size();
        sort(nums.begin(),nums.end());

        for (int i=0; i<n-1; ++i) {
            int left = i+1, right = n-1;
            if (nums[i] > 0) break;
            if (i>0 && nums[i] == nums[i-1]) continue;

            while(left<right) {
                if (nums[i] + nums[left] +nums[right] == 0) {
                    ans.push_back({nums[left], nums[i], nums    [right]});
                    while(left < right && nums[left]==nums[left+1]) left=left+1;
                    while(left < right && nums[right]==nums[right-1]) right=right-1;
                    left+=1;
                    right-=1;
                    continue;
                }
                if (nums[i] + nums[left] +nums[right] < 0) {
                    left+=1;
                    continue;
                }
                if (nums[i] + nums[left] +nums[right] > 0) {
                    right-=1;
                    continue;
                }
            }
        }
        return ans;
    }
};
