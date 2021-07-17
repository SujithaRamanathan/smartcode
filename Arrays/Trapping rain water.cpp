o(n2) - traversing arr element and for each ele finding leftmax and rmax
o(n) o(n) -calculating lmax,rmax and storing in array & directly using it.
0(n) o(1)-find " " on the flow when finding trap water area.. 




 int n = height.size();
        
        if(n<3)
            return 0;
        
        vector<int>maxleft(n);
        vector<int>maxright(n);
        maxleft[0]=0;
        int leftmax=height[0];

        for(int i=1;i<n-1;i++)
        {
            maxleft[i]=leftmax;
            leftmax=max(leftmax,height[i]);
        }
        
        

     maxright[n-1]=0;
        int rightmax=height[n-1];

        for(int i=n-2;i>0;i--)
        {
            maxright[i]=rightmax;
            rightmax=max(rightmax,height[i]);
        }
        
        int trapwater=0;
        for(int i=1;i<n-1;i++)
        {
            if(height[i]<maxleft[i] and height[i]<maxright[i] )
                
            trapwater+=min(maxleft[i],maxright[i])-height[i];
        }
        
        return trapwater;
    }
};