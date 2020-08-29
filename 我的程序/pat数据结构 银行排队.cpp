#include<stdlib.h>
#include<stdio.h>

void show(int);

int main() {
    int n;
    scanf("%d",&n);
    int a[1001];
    for(int m=0; m<n; m++) {
        scanf("%d",&a[m]);
    }
    int i=0,j=0;
    while(i<n||j<n) {
        for(; i<n; i++)
            if(1==a[i]%2) {

                show(a[i++]);
                break;
            }
        for(; i<n; i++) {
            if(1==a[i]%2) {
                show(a[i++]);
                break;
            }
        }
        for(; j<n; j++) {
            if(0==a[j]%2) {
                show(a[j++]);

                break;
            }
        }
    }

    return 0;
}
void show(int num) {
    static int flag=0;

    if(flag)printf(" ");
    else flag=1;

    printf("%d",num);

}
