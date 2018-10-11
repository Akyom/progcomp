#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    int i=1,j,n,mayor,aux;
    while(i<=t){
        scanf("%d",&n);
        scanf("%d",&mayor);
        for(j=1;j<n;++j){
            scanf("%d",&aux);
            if(aux>mayor)mayor=aux;
        }
        printf("Case %d: %d\n",i,mayor);
        ++i;
    }
    return 0;
}
