
Method 1:Simple sorting O(nlogn)


Method 2: Similar to Dutch National Flag Problem O(N)
Actual dutch:-(seg 0,1,2)
Forward pass(0 - n)(maintaining start ptr)
if a[i]< x
 swap with leftmost index
Backward pass(n-1 to when we reach element which is lesser than x) 
if a[i] > x
  swap with rightmost index



=================================================


void threeWayPartition(vector<int>& arr,int a, int b)
    {
    
   int n = arr.size();
   int start=0;
   int end=n-1;
  
  for(int i=0; i<=end;)
  {
      if(arr[i]<a){                  // if element < a (swap it with leftmost element) then start++(since leftmost is occupied)
      swap(arr[i],arr[start]);        
      start++;
      i++;                         // also wre traversing the array only from left to right
      
      }
      
      else if(arr[i] > b)
      {
          swap(arr[i],arr[end]);
          end--;                    // no i++; since we r again checking the swapped element
          
      }
      else
      i++;
  }
}

    
};