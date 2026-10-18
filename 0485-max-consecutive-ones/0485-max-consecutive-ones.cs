public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
        int globalMax = 0;
        int currMax = 0;
        for(int i = 0; i < nums.Length; i++){
            if(nums[i] == 1){
                currMax++;
            }
            else{
                currMax = 0;
            }
            globalMax = Math.Max(globalMax, currMax);
        }
        return globalMax;
    }
}