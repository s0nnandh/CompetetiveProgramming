#include<bits/stdc++.h>
#define int long long
using namespace std;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve(){
    int n;cin>>n;
    int a,b,area,areax[n-1];
    vector<pair<int,int>> p(n);
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++){cin>>a>>b;x[i]=a;y[i]=b;p[i].first=x[i],p[i].second=y[i];}
    vector<pair<int,int>> p1(n);
    p1=p;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(p.begin(),p.end());
    vector<int> x1(n);
    x1=x;    
    sort(p1.begin(),p1.end(),sortbysec);
    int mx,my,Mx,My;
    mx=Mx=p1[0].first;my=My=p1[0].second;
    //areax[0]=(x[n-1]-x[0])*(y[n-1]-y[1]);
    for(int i=0;i<n-1;i++){
        My=p1[i].second;
        if(p1[i].first<mx)mx=p1[i].first;
        else if(p1[i].first>Mx)Mx=p1[i].second;
        areax[i]=(y[i]-y[0])*(Mx-mx);
    }
    for(auto i : areax)cout << i << " ";
    cout << endl;
    mx=Mx=p1[n-1].first;my=My=p1[n-1].second;
    for(int i=n-2;i>=0;i--){
        my=p1[i+1].second;
        if(p1[i + 1].first<mx)mx=p1[i + 1].first;
        else if(p1[i + 1].first>Mx)Mx=p1[i + 1].first;
        if(i >= 1)areax[i-1]+=(y[n-1]-y[i])*(Mx-mx);
    }
    for(auto i : areax)cout << i << " ";
    cout << endl;
    area=areax[0];a=0;b=0;
    for(int i=1;i<n-1;i++){if(area>areax[i]){area=areax[i];b=i;}}
    //cout<<areax[1]<<" a  "<<"\n";
    mx=Mx=p[0].first;my=My=p[0].second;
    //areax[0]=(y[y.size()-1]-y[0])*(x1[n-1]-x1[1]);
    for(int i=0;i<n-1;i++){
        Mx=p[i].first;
        if(p[i].second<my)my=p[i].second;
        else if(p[i].second>My)My=p[i].second;
        areax[i]=(x1[i]-x1[0])*(My-my);
       // if(i==1)cout<<areax[i]<<" a  "<<"\n";
    }
    for(auto i : areax)cout << i << " ";
    cout << endl;
    mx=Mx=p[n-1].first;my=My=p[n-1].second;
    //for(int i=0;i<n;i++)cout<<p[i].second<<"\n";
    for(int i=n-2;i>=0;i--){
        mx=p1[i+1].first;
        if(p1[i + 1].second<my)my=p1[i + 1].second;
        else if(p1[i + 1].second>My)My=p1[i + 1].second;
        if(i >= 1)areax[i-1]+=(x1[n-1]-x1[i])*(My-my);
        cout << (x1[n-1]-x1[i])*(My-my) << endl;
        //if(i==1)cout<<areax[i]<<" b "<<my<<"  c"<<My<<"d ";
    }
    for(auto i : areax)cout << i << " ";
    cout << endl;
    for(int i=0;i<n-1;i++){if(area>areax[i]){area=areax[i];b=i;a=1;}}
    //if(areax>areay)cout<<areay<<"\n";
    cout<<area<<"\n";//<<" "<<a<<" "<<b<<"\n";
    return ;
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}