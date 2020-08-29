
#include <stdio.h>
#define N 20
int main(void) {
	int i, j, k, n1, n2, flag, flag2;
	int a[N], b[N], c[N];
	scanf("%d", &n1);
	for(i = 0; i < n1; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &n2);
	for(i = 0; i < n2; ++i)
		scanf("%d", &b[i]);
	k = 0;



	for(i = 0; i < n1; ++i) {
		//flag = 0;
		[[[for(j = 0; j < n2; ++j) {
			if(a[i] == b[j]) {
				//flag = 1;
				break;
			}
		}]]]

		if(!flag) {
			//flag2 = 0;
			for(j = 0; j < k; ++j) {
				if(c[j] == a[i]) {
					flag2 = 1;
					break;
				}
			}
			if(!flag2)
				c[k++] = a[i];
		}
	}



	for(i = 0; i < n2; ++i) {
		flag = 0;
		for(j = 0; j < n1; ++j) {
			if(b[i] == a[j]) {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			flag2 = 0;
			for(j = 0; j < k; ++j) {
				if(c[j] == b[i]) {
					flag2 = 1;
					break;
				}
			}
			if(!flag2)
				c[k++] = b[i];
		}
	}





	for(i = 0; i < k - 1; ++i)
		printf("%d ", c[i]);
	printf("%d\n", c[k - 1]);
	return 0;
}

