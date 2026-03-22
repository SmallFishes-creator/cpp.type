#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int sz = nums.size();
        for(int i = 0;i <= ((1 << sz) - 1);i++)
        {
            vector<int> tmp;
            for(int j = 0;j < sz;j++)
            {
                if((i >> j) & 1)
                    tmp.push_back(nums[j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums;
    int sz;
    cin >> sz;
    for(int i = 0;i < sz;i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    Solution s1;
    vector<vector<int>> ans = s1.subsets(nums);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}