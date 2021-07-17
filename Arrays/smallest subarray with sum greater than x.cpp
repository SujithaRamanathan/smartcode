o(n2)

o(n) 


int sb(int a[], int n, int x)
  {
        int minlength = INT_MAX;
        
        for(int i=0;i<n;i++) {
        int current_sum = a[i];
        if(current_sum > x)
        return 1;
        for(int j=i+1;j<n;j++)
        {
            current_sum += a[j];
            if(current_sum > x && j-i+1 < minlength)
            minlength = j-i+1;
        }
        }
        return minlength;
    }
};
