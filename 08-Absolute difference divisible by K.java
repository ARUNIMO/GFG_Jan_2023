/*

Given an array of integers of size n and an integer k, find all the pairs in the array whose absolute difference is divisible by k.

Example 1:

Input:
n = 3
arr[] = {3, 7, 11}
k = 4
Output:
3
Explanation:
(11-3) = 8 is divisible by 4
(11-7) = 4 is divisible by 4
(7-3) = 4 is divisible by 4

Example 2:

Input:
n = 4
arr[] = {1, 2, 3, 4}
k = 2
Output :
2
Explanation:
Valid pairs are (1,3), and (2,4).

Your Task:  
You don't need to read input or print anything. Your task is to complete the function countPairs() which takes integers n, array arr[ ], integer k as input parameters and returns the number of pairs whose absolute difference is divisible by k.
Note: The answer may be large so use 64-bit integer. 


Expected Time Complexity: O(n + k)
Expected Auxiliary Space: O(k)


Constraints:
2 ≤ n ≤ 105
1 ≤ k,arr[i] ≤ 105
*/

//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
	public static void main(String args[]) throws IOException {
		BufferedReader read =
		new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(read.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(read.readLine());
			String S[] = read.readLine().split(" ");
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = Integer.parseInt(S[i]);
			int k = Integer.parseInt(read.readLine());

			Solution ob = new Solution();
			System.out.println(ob.countPairs(n, arr, k));
		}
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution {
	static long countPairs(int n, int[] arr, int k) {
		// code here
		long ans =0; 

        int a[] = new int[k];

        for(int i:arr){

              a[i%k]++;

        }

        for(int i=0; i<k; i++){

               ans = ans + (a[i]*(a[i]-1))/2;

         }

        return ans;
	}
}
