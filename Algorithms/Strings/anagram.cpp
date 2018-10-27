#include <cstdlib>
using namespace std;
#define neww we
int main() {
	int testc;
	cin>>testc;
	for(int i=0;i<testc;i++)
	{
	    string a,b;
	    cin>>a>>b;
	    if(a.length()!=b.length())
	    {
	        cout<<"NO"<<"\n";
	    }
	    else
	    {
	        int p=a.length();
	        int cnt=a.length();
	        int flag[p];
	        for(int y=0;y<p;y++)
	        {
	            flag[y]=0;
	        }	        
	        for(int y=0;y<p;y++)
	        {
	            for(int k=0;k<p;k++)
	            {
	                if(flag[k]==0)
	                {
	                    if(a[y]==b[k])
	                    {
	                        flag[k]=1;
	                        cnt--;
	                        break;
	                    }
	                }
	            }
	        }
	        if(cnt==0)
	            cout<<"YES"<<"\n";
	        else
	            cout<<"NO"<<"\n";
	    }
	}
	return 0;
}
