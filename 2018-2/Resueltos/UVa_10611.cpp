#include <bits/stdc++.h>
using namespace std;

int bb(int p,int v[],int n,int u,int e,int f){
    int medio=(n+u)/2;
    if((v[medio]==p)||(e==medio)||(f==medio)){
        return medio;
    }
    else{
        if(v[medio]<p){
            e=medio;
            return bb(p,v,n,medio,e,f);
        }
        if(v[medio]>p){
            f=medio;
            return bb(p,v,medio,u,e,f);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int v[n];
    for(int i=0;i<n;++i){
        scanf("%d",&v[i]);
    }
    int q,p,m[2],pos;
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        scanf("%d",&p);
        pos=bb(p,v,n,0,-1,-1);
        int j=pos,k=0;
        while(j<n){
            if(v[j]>p){
                k=1;
                break;
            }
            ++j;
        }
        if(k)m[1]=v[j];
        else m[1]=-1;
        k=0;
        j=pos;
        while(j>=0){
            if(v[j]<p){
                k=1;
                break;
            }
            --j;
        }
        if(k)m[0]=v[j];
        else m[0]=-1;
        if((m[0]!=-1)&&(m[1]!=-1))printf("%d %d\n",m[0],m[1]);
        else{
            if(m[0]==-1){
                printf("X ");
                if(m[1]==-1)printf("X\n");
                else printf("%d\n",m[1]);
            }        
            else{
                printf("%d ",m[0]);
                if(m[1]==-1)printf("X\n");
                else printf("%d\n",m[1]);
            }
        }
    }
    return 0;
}

