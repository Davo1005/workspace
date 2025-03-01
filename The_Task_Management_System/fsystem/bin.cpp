class Solution {
    public:
        int search(vector<int>& nums, int target int start, int end) {

            if(start == end && nums[start] != target)
            {
                return -1;
            }
            if(nums[(start + end)/2 <= target])
            {
                {if(nums[(start + end)/2] == target)
                {
                    return (start + end)/2;
                }
                start = (start + end)/2;
                }
                return search(nums, target, start, end);
            }
            else
            {
                end = (start + end)/2;
                return search(nums, target, start, end);
            }
        }
    };