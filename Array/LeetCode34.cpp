class Solution {
public:
    int getFirstPosition(vector<int>& nums, int target) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        int midIndex = 0;
        bool isFind = false;
        while(leftIndex <= rightIndex) {
            midIndex = leftIndex + (rightIndex - leftIndex) / 2;
            if(nums[midIndex] >= target) {
                if(nums[midIndex] == target) {
                    isFind = true;
                }
                rightIndex = midIndex - 1;
            }
            else {
                leftIndex = midIndex + 1;
            }
        }
        return isFind == true ? leftIndex : -1;
    }
    
    int getLastPosition(vector<int>& nums, int target) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        int midIndex = 0;
        bool isFind = false;
        while(leftIndex <= rightIndex) {
            midIndex = leftIndex + (rightIndex - leftIndex) / 2;
            if(nums[midIndex] <= target) {
                if(nums[midIndex] == target) {
                    isFind = true;
                }
                leftIndex = midIndex + 1;
            }
            else {
                rightIndex = midIndex - 1;
            }
        }
        return isFind == true ? rightIndex : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPosition = getFirstPosition(nums, target);
        int lastPosition = getLastPosition(nums, target);
        return {firstPosition, lastPosition};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto iterFirst = lower_bound(nums.begin(), nums.end(), target);
        int firstIndex = distance(nums.begin(), iterFirst);

        //没有值大于等于target或者没有值等于target
        if(iterFirst == nums.end() || *iterFirst != target) {
            return {-1, -1};
        }
        else {
            auto iterLast = upper_bound(nums.begin(), nums.end(), target) - 1;
            int lastIndex = distance(nums.begin(), iterLast);
            return {firstIndex, lastIndex};
        }
    }
};
