class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int lazy = nums[0];
        do{
            fast = nums[fast];
            lazy = nums[nums[lazy]];
        }while(fast != lazy);

        fast = nums[0];
        while(fast != lazy){
            fast = nums[fast];
            lazy = nums[lazy];
        }
        return fast;
    }
};
