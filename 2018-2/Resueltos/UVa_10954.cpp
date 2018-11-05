#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        vector<long long> v(n);
        for(int i=0;i<n;++i){
            scanf("%lld",&v[i]);
        }
        sort(v.begin(),v.end());
        long long s=v[0]+v[1];
        long long s2=0;
        s2+=s;
        v[1]=s;
        for(int i=1;i<n-1;++i){
            sort(v.begin(),v.end());
            s=v[i]+v[i+1];
            s2+=s;
            v[i+1]=s;
        }
        if(n < 2) s2=0;
        printf("%lld\n",s2);
        scanf("%d",&n);
    }
    return 0;
}