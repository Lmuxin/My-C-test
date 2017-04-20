#include<stdio.h>
struct Poly{
    int expon;
    int coef;
}Poly[1001];
int main(){
    int m,n,a[2005]={0},b[1005]={0};

    scanf("%d",&m);
    int p,q;

    for(int i=0;i<a;i++){
        scanf("%d%d",&Poly[i].coef,&Poly[i].expon);
        B[Poly[i].expon]+=Poly[i].coef;
    }
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d%d",&p,&q);
        B[q]+=p;
        for(int j=0;j<m;j++)
            a[q+Poly[j].expon]+=(p*Poly[j].coef);
    }
    int f1=1,f2=0;
    for(int i=2000;i>=0;i--){
        if(a[i]!=0){
            if(!f1)    printf(" %d %d",a[i],i);
            if(f1){
                f1=0;
                printf("%d %d",a[i],i);
            }
            f2=1;
        }
    }

    if(!f2) printf("0 0");
    f2=0;
    f1=1;
    putchar('\n');
    for(int i=1000;i>=0;i--){
        if(b[i]!=0){
            if(!f1)        printf(" %d %d",b[i],i);
            if(f1){
                printf("%d %d",b[i],i);
                f1=0;
            }
            f2=1;
        }

    }
    if(!f2) printf("0 0");
    return 0;
}
