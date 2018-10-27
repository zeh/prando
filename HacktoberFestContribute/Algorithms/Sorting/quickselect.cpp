/*
    @author: Priyendu Mori
    Find the nth smallest element in an unordered array using randomized quick sort 
    and comparison with STL's nthelement()
*/

#include <bits/stdc++.h>
#define ll long long

using namespace std;

/*
    partitions vector such that elements to the left of a[i] 
    are less than a[i] and to the right are greater than a[i] 
    and returns index i where it is partitoned 
*/
ll partition(vector<ll> &a, ll low, ll high){ 
    ll pivot = a[high];
    ll i = low;
  
    for (ll j=low; j<=high - 1; j++){ 
        
        if (a[j]<=pivot) {   
            ll temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++; 
        } 
    } 
    ll temp=a[i];
    a[i]=a[high];
    a[high]=temp;
    return i;
}

/*
    finds kth smallest element of the vector a
    using random pivot element
*/
void kthSmallest(vector<ll> &a, ll low, ll high, ll k){ 
    if (low<=high){
        //generate a random number in the range low to high
        ll random;
        if(low==high)   random=low; 
        else    random = low + rand() % (high - low); 
        
        //swap a[random] with a[high] as last element is used as pivot
        ll temp=a[random];
        a[random]=a[high];
        a[high]=temp;

        //calling partition after swapping, so now randomly 
        //generated pivot will be at it's correct position
        ll pi = partition(a, low, high);
        
        //if pivot returns index k than the number at index k has taken 
        //it's correct position, so it is the kth smallest element
        //else if returns index(pi) greater than k, we should search in the left of pi
        //else search in right
        if(pi==k){
            cout<<a[k]<<endl;
            return;
        } 
        else if(pi>k)   kthSmallest(a, low, pi - 1, k); 
        else    kthSmallest(a, pi + 1, high, k); 
    } 
} 

int main(){
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n,INT32_MAX);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    clock_t t; 
    t = clock(); 
    cout<<"My nth smallest"<<endl;
    kthSmallest(a,0,a.size()-1,k-1);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 

    cout<<time_taken<<endl;

    t = clock(); 
    nth_element(a.begin(),a.begin()+k-1,a.end());
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    cout<<endl<<"STL nth_element"<<endl;
    cout<<a[k-1]<<endl;
    cout<<time_taken<<endl;
    
    /*while(1){
        cin>>k;
        cout<<"at "<<k<<" ";
        kthSmallest(a,0,a.size()-1,k-1);
        cout<<endl;
    } */   

    return 0;
}
