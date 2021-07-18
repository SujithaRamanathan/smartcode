Searching in an array where adjacent differ by atmost k:-
========================================================

simple approach:-
traverse the array;
since given that adjacent differ by atmost k, we have to increment i as max(1,(abs(a[i]- key))/2; vvvvvvvvvvvvimppppp

while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i]-x)/k);
    }
 
    cout << "number is not present!";
    return -1;
}
 