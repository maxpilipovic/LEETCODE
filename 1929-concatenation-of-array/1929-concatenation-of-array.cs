public class Solution {
    public int[] GetConcatenation(int[] nums) 
    {
        int n = nums.Length;

        int[] ans = new int[nums.Length * 2];

        for (int i = 0; i < nums.Length*2; i++) {
            if (i < n) {
                ans[i] = nums[i];
            }
            else {
                ans[i] = nums[i - n];
            }
        }
        return ans;
    }
}