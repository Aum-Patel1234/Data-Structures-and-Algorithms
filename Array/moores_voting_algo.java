package Array;

public class moores_voting_algo {
    public static void main(String[] args) {
        int[] arr = {2,2,1,1,1,2,2};
        /*  
        now we have to find the majority element which have occured more than n/2 times in the arr
        the most efficient way is to use moores majority voting algorithm which works on the idea that - 
            if there is a majority element which is occuring more than n/2 times in the array then the frequecy of the element whill be more than 0
            even if the freq is reduced - 
                if(arr[i] == majority_element) freq++;
                else freq-- 
        
        link - https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
        */
        System.out.println(majorityElement(arr));
    }
    public static int majorityElement(int[] nums) {
        // moores voting algorithm
        
        return helper(nums,nums[0],0);
    }
    private static int helper(int[] arr,int element,int start){
        int freq = 0;

        for(int i = start ; i < arr.length;i++){
            if(arr[i] == element){
                freq++;
            }else{
                freq--;
            }
            
            if(freq <= 0){
                return helper(arr,arr[i],i);
            }
        }
        return element;
    }
}
