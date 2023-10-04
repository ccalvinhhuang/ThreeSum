#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; ++i){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int l = i + 1, h = nums.size() - 1;
        while(l < h){
            int three_sum = nums[i] + nums[l] + nums[h];
            if(three_sum < 0){
                l++;
            }
            else if(three_sum > 0){
                h--;
            }
            else{
                ans.push_back({nums[i], nums[l], nums[h]});
                while(l < h && nums[l] == nums[l + 1]){
                    l++;
                }
                while(l < h && nums[h] == nums[h - 1]){
                    h--;
                }
                l++, h--;
            }
        }
    }
    return ans;
}
