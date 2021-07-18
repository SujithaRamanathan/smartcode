checking if a given no is in ARITHMETIC sequence
================================================

simply, the difference between the given x value and first value should be completely divisible by 
common difference and also the quotient of the division should be non-negative
==========================================================================


class Solution{
public:
    int inSequence(int A, int B, int C){
        if(C == 0)                                  /////////////////////VVVIMP ( if common diff = 0 then a == b means yes else no)
        return (A==B);
        
        int diff = 0;
        diff = B-A;
        
        return ( (diff % C == 0) and (diff / C >= 0));
    }
};