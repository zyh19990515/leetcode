#include <vector>
#include <iostream>
using namespace std;

#if 0 
int main()
{
    vector<vector<int>> p1;
    vector<int> temp;
    for (int j = 0; j < 5; j++)
    {
        temp.push_back(j);
    }
    for (int i = 0; i < 5; i++)
    {
        p1.push_back(temp);
    }
    cout << p1[2].size() << endl;
    cout << p1[2][2] << endl;
    p1[2].erase(p1[2].begin() + 2);
    cout << p1[2].size() << endl;
    cout << p1[2][2] << endl;
    return 0;
}
#endif


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int rightBorder = getRightBorder(nums, target);
        int leftBorder = getLeftBorder(nums, target);
        if (leftBorder == -2 || rightBorder == -2) return { -1,-1 };
        if (rightBorder - leftBorder > 1) return { leftBorder + 1,rightBorder - 1 };
        return { -1,-1 };
    }
private:
    int getRightBorder(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (target < nums[mid])
            {
                right = mid - 1;
            }
            else if (target >= nums[mid])
            {
                left = mid + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (target <= nums[mid])
            {
                right = mid - 1;
                leftBorder = right;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
        }
        return leftBorder;
    }
};


int main()
{
    vector<int> nums = { 5,7,7,8,8,10 };
    int target = 8;
    Solution A;
    vector<int> result = A.searchRange(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}