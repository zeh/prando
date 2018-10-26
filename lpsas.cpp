string Solution::longestPalindrome(string A) {
    int n,start=0,maxlen=1,low,high,i;
    n=A.length();
    if(n<2)
        return A;
    string lps="";
    for(i=1;i<n;i++)
    {
        low=i-1;
        high=i;
        while(low>=0 && high<n && A[low]==A[high])
        {
            if(high-low+1>maxlen)
            {
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
        low=i-1;
        high=i+1;
        while(low>=0 && high<n && A[low]==A[high])
        {
            if(high-low+1>maxlen)
            {
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
    }
    for(i=start;i<start+maxlen;i++)
        lps+=A[i];
    return lps;
}
