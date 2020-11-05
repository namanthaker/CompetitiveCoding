/*							First Missing Integer


Problem Description

Given an unsorted integer array A of size N. Find the first missing positive integer.

Note: Your algorithm should run in O(n) time and use constant space.



Problem Constraints
1 <= N <= 1000000

-109 <= A[i] <= 109



Input Format
First argument is an integer array A.



Output Format
Return an integer denoting the first missing positive integer.



Example Input
Input 1:

[1, 2, 0]
Input 2:

[3, 4, -1, 1]
Input 3:

[-8, -7, -6]


Example Output
Output 1:

3
Output 2:

2
Output 3:

1


Example Explanation
Explanation 1:

A = [1, 2, 0]
First positive integer missing from the array is 3.



code : 
*/
int Solution::firstMissingPositive(vector<int> &A) {
    int n=A.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(A[i]<=0){
            swap(A[i],A[j]);
            j++;
        }
    }
    for(int i=j;i<n;i++){
        if(abs(A[i])+j-1>=0&&abs(A[i])+j-1<n){
         if(A[abs(A[i])+j-1]>0)
           A[abs(A[i])+j-1]=-A[abs(A[i])+j-1];
        }
    }
    for(int i=j;i<n;i++){
       // cout<<A[i]<<"\n";
        if(A[i]>0)
         return (i-j+1);
    }
    return (n-j+1);
}