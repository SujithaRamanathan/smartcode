
qn1)
Given an array of positive integers. We need to make the given array a ‘Palindrome’. 
The only allowed operation is”merging” (of two adjacent elements). Merging two adjacent 
elements means replacing them with their sum. The task is to find the minimum number of merge 
operations required to make the given array a ‘Palindrome’.To make any array a palindrome, we can 
simply apply merge operation n-1 times where n is the size of the array (because a single-element array is always palindromic, 
similar to single-character string). In that case, the size of array will be reduced to 1. But in this problem, we are asked to
 do it in the minimum number of operations.

Approach:- O(N)
-----------------
Shrinking the array and check for palindrome until a single element(if not find palindromic till that)

Maintain 2 ptrs (low & high)
traverse the array (while loop)
if(element are matching)
move innerwards(i++,j--)
if(does not matching)
choose the element which is smaller and merge it with its adjacent
change only the ptr which gets merged


*****main thing is to maintain the result count of operations****

         cin >> a[i];
        int res=0,low=0,high=n-1;
        while(low <= high) {
                if(a[low]==a[high]){
                       low++;
                        high--; }
                else if(a[low] < a[high]){
                        low++;
                        a[low] = a[low] + a[low-1];
                        res++;
                }
                else {
                        high--;
                        a[high] = a[high] + a[high+1];
                        res++;
                }
        }

          cout << res << endl;



===========================================================================================================



qn 2)

Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. 
Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

Approach:O(N2)

int PalinArray(int a[], int n)
{  
    for(int i=0;i<n;i++)
    {
        int temp = a[i];
        int ans = 0;
        while(temp>0)
        {
            int r = temp % 10;
            temp = temp/10;
            
            ans = (ans * 10) + r;
        }
        if(ans != a[i])
        return 0;
    }
return 1;
    }


==========================================================