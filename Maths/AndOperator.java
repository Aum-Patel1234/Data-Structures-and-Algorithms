package Maths;

public class AndOperator{
    class Solution {
        public int largestCombination(int[] candidates) {
            int maxCombination = 0;
    
            // Iterate over each bit position from 0 to 24 (assuming numbers are up to 2^24)
            for (int bit = 0; bit < 24; bit++) {
                int count = 0;
    
                // Count how many numbers have the current bit set
                for (int candidate : candidates) {
                    if ((candidate & (1 << bit)) != 0) {
                        count++;
                    }
                }
    
                // Update maxCombination with the highest count for any bit position
                maxCombination = Math.max(maxCombination, count);
            }
    
            return maxCombination;
        }
    }
    public static void main(String[] args) {
        // Using 23 bits in the initial solution is a way of optimizing based on the assumption that the input values in `candidates` are relatively small, which is typical in many problem constraints where numbers stay within the range of 2^24 (around 16 million).

        // Here’s why only checking 23 bits was initially suggested:

        // 1. **Bit Range Assumption**: Many problems specify that input values are smaller than 2^24, or 16,777,216, which fits within 24 bits. For numbers up to 2^24, only bits `0` to `23` would be potentially non-zero, so there's no need to check beyond the 23rd bit.

        // 2. **Efficiency**: Each bit position check requires iterating over all elements in `candidates`. Limiting the bit checks to 24 (instead of 32) saves computation time when the input values are guaranteed to be small.

        // 3. **Integer Size Constraints**: If the values are indeed limited to numbers that can be represented within 24 bits, then checking bits beyond `23` would be redundant since they would all be `0` in every integer.

        // 4. **Real-World Usage**: In competitive programming, it’s common to optimize based on known input constraints to make solutions run faster. For example, if numbers are small, optimizing for fewer bits is a good tradeoff.

        // However, if the problem does not specify an upper bound for the numbers and they can potentially use the full range of a 32-bit integer (up to 2^31 - 1), it would be safer to check all 32 bits. In this case, adjusting the solution to loop through `0` to `31` would ensure coverage for any 32-bit integer.

    }    
}