stickler thief/maxloot/maximum sum subsequence where no two elements are adjacent
=============================================================================

we can make use of dp array of same size n. in dp array the element at i represent the maximum sum till i without taking adjacent elements;

initialise dp[0] = a[0];
                 dp[1] = max(a[0] , a[1]);
	
for(int i = 2;i<n;i++)
dp[i] = max(a[i] + dp[i-2] , dp[i-1]);               see keenly,it will understood;
                              |                    | -> not considering current
	considering current element          of the two we are finding maximum.
return dp[n-1];

=================================================