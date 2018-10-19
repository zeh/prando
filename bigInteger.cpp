/*
    @author: Priyendu Mori
    Big Integer library that supports add, sub, mul, div and gcd of large numbers
*/
#include <bits/stdc++.h>
#include <string>
#define ll long long

using namespace std;

string add(string, string);
string sub(string, string);

bool isSmaller(string x, string y) 
{ 
    for (ll i=0; i<x.length(); i++){
        if (x[i] < y[i]) return true; 
        else if (x[i] > y[i]) return false; 
    }
    return false; 
} 

bool isGreater(string x, string y){
    if(x.length() > y.length()) return true;

    ll pad=llabs(x.length()-y.length());
    if(x.length()<y.length()){
        x=string(pad, '0').append(x);
    }
    else{
        y=string(pad, '0').append(y);
    }

    for (ll i=0; i<x.length(); i++){
        if (x[i] > y[i]) return true; 
        else if (x[i] < y[i]) return false; 
    }
    return false; 
}

bool isEqual(string x, string y){

    ll pad=llabs(x.length()-y.length());
    if(x.length()<y.length()){
        x=string(pad, '0').append(x);
    }
    else{
        y=string(pad, '0').append(y);
    }

    for (ll i=0; i<x.length(); i++){
        if (x[i] != y[i]) return false; 
    }
    return true; 
}

bool isZero(string x){
    for(ll i=0;i<x.length();i++){
        if(x[i] != '0') return false;
    }
    return true;
}

string sub(string x, string y){

    bool neg=false;

    if(x[0]=='-' && y[0]=='-'){
        string temp=x;
        x=y;
        y=temp;
        y=y.substr(1,y.length()-1);
        x=x.substr(1,x.length()-1);
    }
    else if(x[0]!='-' && y[0]=='-'){
        y=y.substr(1,y.length()-1);
        return add(x,y);
    }
    else if(x[0]=='-' && y[0]!='-'){
        x=x.substr(1,x.length()-1);
        string ans="-"+add(x,y);
        return ans;
    }

    ll pad=llabs(x.length()-y.length());
    if(x.length()<y.length()){
        x=string(pad, '0').append(x);
    }
    else{
        y=string(pad, '0').append(y);
    }

    if(isSmaller(x, y)){
        string temp=x;
        x=y;
        y=temp;
        neg=true;
    }

    string diff="";

    int carry=0;
    for(ll i=x.length()-1;i>=0;i--){
        ll d = (x[i]-'0') - (y[i]-'0') - carry;

        if(d < 0){
            d=d+10;
            carry=1;
            diff.push_back(d+'0');
        }
        else{
            carry=0;
            diff.push_back(d+'0');
        }  
    }
    
    reverse(diff.begin(), diff.end()); 
    diff.erase(0, min(diff.find_first_not_of('0'), diff.length()-1));
    if(neg) diff.insert(diff.begin(),'-');
    return diff;
    
}

string add(string x, string y){

    bool neg=false;
    if(x[0]=='-' && y[0]!='-'){
        x=x.substr(1,x.length()-1);
        return sub(y, x);
    }
    else if(x[0]!='-' && y[0]=='-'){
        y=y.substr(1,y.length()-1);
        return sub(x, y);
    }
    else if(x[0]=='-' && y[0]=='-'){
        neg=true;
        x=x.substr(1,x.length()-1);
        y=y.substr(1,y.length()-1);
    }
    ll pad=llabs(x.length()-y.length());
    if(x.length()<y.length()){
        x=string(pad, '0').append(x);
    }
    else{
        y=string(pad, '0').append(y);
    }

    string sum="";

    int carry=0;
    for(ll i=x.length()-1;i>=0;i--){
        ll s = x[i]-'0' + y[i]-'0' + carry;

        if(s <= 9){
            sum.push_back(s+'0');
            carry=0;
        }
        else{
            sum.push_back(s%10 +'0');
            carry=s/10;
        }  
    }
    if(carry!=0){
        sum.push_back(carry+'0');
    }
    if(neg) sum.push_back('-');

    reverse(sum.begin(), sum.end()); 
    sum.erase(0, min(sum.find_first_not_of('0'), sum.length()-1));
    return sum;

}

string mul(string x, string y){

    bool neg=false;

    if(x[0]=='-' && y[0]=='-'){
        x=x.substr(1,x.length()-1);
        y=y.substr(1,y.length()-1);
    }
    else if(x[0]=='-' && y[0]!='-'){
        x=x.substr(1,x.length()-1);
        neg=true;
    }
    else if(x[0]!='-' && y[0]=='-'){
        y=y.substr(1,y.length()-1);
        neg=true;
    }

    string finalproduct="";
    for(ll i=0;i<y.length();i++){
        ll multiplier=y[i]-'0';
        string product="";

        int carry=0;
        //cout<<"multiplying "<<multiplier<<" and "<<x<<endl;
        for(ll j=x.length()-1;j>=0;j--){
            
            int p=(x[j]-'0')*multiplier + carry;
            if(p<=9){
                product.push_back(p+'0');
                carry=0;
            }
            else{
                product.push_back(p%10 + '0');
                carry=p/10;
            }
        }
        if(carry!=0) product+=carry+'0';
        //cout<<"ans "<<product<<endl;

        if(i==0){
            reverse(product.begin(), product.end());
            finalproduct=product;
        }
        else{
            finalproduct+='0';
            reverse(product.begin(), product.end());
            //cout<<"adding "<<finalproduct<<" and "<<product<<endl;
            finalproduct=add(finalproduct, product);
        }
    }

    if(neg) finalproduct.insert(finalproduct.begin(), '-');
    return finalproduct;
}

string div(string x, string y){
    bool neg=false;

    if(x[0]=='-' && y[0]=='-'){
        x=x.substr(1,x.length()-1);
        y=y.substr(1,y.length()-1);
    }
    else if(x[0]=='-' && y[0]!='-'){
        x=x.substr(1,x.length()-1);
        neg=true;
    }
    else if(x[0]!='-' && y[0]=='-'){
        y=y.substr(1,y.length()-1);
        neg=true;
    }

    ll pad=llabs(x.length()-y.length());
    if(x.length()<y.length()){
        x=string(pad, '0').append(x);
    }
    else{
        y=string(pad, '0').append(y);
    }

    if(isSmaller(x,y)) return "0";

    string count="0";
    while(isGreater(x, y)){
        //cout<<x<<" - "<<y<<" = ";
        x=sub(x, y);
        //cout<<x<<"\t";
        count=add(count, "1");
        //cout<<count<<endl;
        // cout<<"isGreater("<<x<<","<<y<<") = "<<isGreater(x ,y)<< endl;
    }

    if(isEqual(x,y)) count=add(count, "1");

    if(neg) return '-'+count;
    return count;
}

string gcd(string x, string y){

    while(!isZero(x) && !isZero(y)){    
        if(isGreater(x,y)){
            x=sub(x,y);
        }
        else if(isGreater(y,x)){
            y=sub(y,x);
        }
        else{
            x=sub(x,y);
        }
    }

    if(isZero(x)){
        return y;
    }

    if(isZero(y)){
        return x;
    }
    return "1";
}

int main(){
    ios_base::sync_with_stdio(false);

    ll t;
    cin>>t;

    while(t--){
        string x,y;
        ll k;

        cin>>x>>y>>k;

        string ans="";
        switch(k){
            case 1: ans=add(x,y); break;
            case 2: ans=sub(x,y); break;
            case 3: ans=mul(x,y); break;
            case 4: ans=div(x,y); break;
            case 5: ans=gcd(x,y); break;
        }

        cout<<ans<<endl;
    }

    return 0;
}
