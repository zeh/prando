#include<bits/stdc++.h>
using namespace std;
#define N 500000
pair<long long int,int> a[N+1],c[N+1];
long long int b;
int bit[N+1];
void update(int ind,int n)
{
    while(ind<=n)
    {
        bit[ind]++;
        ind+=ind&(-ind);
    }
}
long long int que(int ind)
{
    long long int ans=0;
    while(ind>0)
    {
        ans+=bit[ind];
        ind-=ind&(-ind);
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
	long long int cnt,l,r;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	    cin>>b,a[i].first+=a[i-1].first+b,a[i].second=i,c[i]=a[i];
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	    a[c[i].second].second=i;
	while(q--)
	{
        cnt=0;
        cin>>l>>r;
        for(int i=1;i<=n;i++)
        {
            int h=upper_bound(c+1,c+n+1,make_pair(a[i].first-l,INT_MAX))-c;
            int lo=lower_bound(c+1,c+n+1,make_pair(a[i].first-r,INT_MIN))-c;
            if(a[i].first>=l && a[i].first<=r)
                cnt+=1;
            cnt+=que(h-1)-que(lo-1);
             update(a[i].second,n);
        }
        cout<<cnt<<endl;
        for(int i=1;i<=n;i++)
            bit[i]=0;
	}
	return 0;
}
