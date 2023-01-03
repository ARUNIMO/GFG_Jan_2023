/*

N Students of different heights are attending an assembly. The heights of the students are represented by an array H[]. The problem is that if a student has less or equal height than the student standing in front of him, then he/she cannot see the assembly. Find the minimum number of students to be removed such that maximum possible number of students can see the assembly.
 

Example 1:

Input:
N = 6
H[] = {9, 1, 2, 3, 1, 5}
Output:
2
Explanation:
We can remove the students at 0 and 4th index.
which will leave the students with heights
1,2,3, and 5.
Example 2:
Input:
N = 3
H[] = {1, 2, 3} 
Output :
0
Explanation:
All of the students are able to see the
assembly without removing anyone.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function removeStudents() which takes an integer N and an array H[ ] of size N as input parameters and returns the minimum number of students required to be removed to enable maximum number of students to see the assembly.


Expected Time Complexity: O(N logN)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 105
1 ≤ H[i] ≤ 105


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> temp ;
        temp.push_back(H[0]);
        int len = 1;
        
        for(int i= 1 ; i < N ; i++)
        {
            if(H[i] > temp.back())
            {
                temp.push_back(H[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),H[i]) - temp.begin();
                temp[ind] = H[i];
            }
        }
        return N-len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
