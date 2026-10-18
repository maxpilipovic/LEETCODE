public class Solution {
    public int[] FindErrorNums(int[] nums) {
        int numsSize = nums.Length;
        HashSet<int> set = new HashSet<int>();
        int duplicate = -1;

        for(int i = 0; i < numsSize; i++){

            if(set.Contains(nums[i])){
                duplicate = nums[i];
            }

            set.Add(nums[i]);
        }

        for (int i = 1; i <= numsSize; i++)
        {
            if (!set.Contains(i))
            {
                return new int[]{duplicate, i};
            }
        }

        return new[] { duplicate, -1 };
    }
}