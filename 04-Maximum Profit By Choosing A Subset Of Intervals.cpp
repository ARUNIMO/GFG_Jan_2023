/*
Given a list intervals of n intervals, the ith element [s, e, p] denotes the starting point s, ending point e, and the profit p earned by choosing the ith interval. Find the maximum profit one can achieve by choosing a subset of non-overlapping intervals.

Two intervals [s1, e1, p1] and [s2, e2, p2] are said to be non-overlapping if [e1 <= s2] and [s1 < s2].

Example 1:

Input:
n = 3
intervals = {
{1, 2, 4},
{1, 5, 7},
{2, 4, 4}
}
Output:
8
Explanation:
One can choose intervals [1, 2, 4] and [2, 4, 4] for a 
profit of 8.
Example 2:

Input:
n = 3
intervals = {
{1, 4, 4},
{2, 3, 7},
{2, 3, 4}
}
Output:
7
Explanation:
One can choose interval [2, 3, 7] for a profit of 7.
Your Task:

You don't need to print or output anything. Complete the function maximum_profit() which takes an integer n and a 2D integer array intervals and returns an integer, denoting the maximum profit which one can get by choosing the non-overlapping intervals.

Constraints:

1 <= n and n <= 104
1 <= starting point of ith interval < ending point of ith interval <= 105
1 <= profit earned by choosing ith interval <= 105


*/



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
       
        sort(intervals.begin() , intervals.end() , []( vector<int>&a , vector<int>&b ){
            return a[1] != b[1] ? a[1] < b[1] : ( a[0] != b[0] ? a[0] < b[0] : a[2] > b[2]) ;
        });
        
        map<int , int>profits;
        
        profits[-1] = 0;
        for(auto &it : intervals){
            int start = it[0] , end = it[1] , profit = it[2];
            int maxprofit = max( (prev( profits.upper_bound(end) ))->second , 
                            (prev( profits.upper_bound(start) ))->second+ profit ) ;
            profits[end] = maxprofit;
        }
        return profits.rbegin()->second;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends
