
#include <stdio.h>
#include <stdlib.h>

#define INF 50000000

typedef struct coin {
    int price, weight;
} coin;

void dynamicPackage(coin *coins, int n, int v)
{
    if (v < 0) {
        printf("This is impossible.\n");
        return;
    }

    int i, j, *dp;

    // ��̬�����ڴ�
    dp = (int *)malloc(sizeof(int) * (v + 1));

    // ��ʼ��
    dp[0] = 0;
    for (i = 1; i <= v; i ++)    dp[i] = INF;

    // ��ȫ��������
    for (i = 1; i <= n; i ++) {
        for (j = coins[i].weight; j <= v; j ++) {
            dp[j] = (dp[j] < dp[j - coins[i].weight] + coins[i].price) ? dp[j] : dp[j - coins[i].weight] + coins[i].price;
        }
    }

    if (dp[v] >= INF)
        printf("This is impossible.\n");
    else
        printf("The minimum amount of money in the piggy-bank is %d.\n", dp[v]);


    // �����ڴ�
    free(dp);
    dp = NULL;
}


int main(void)
{
    int t, e, f, n, i;
    coin *coins;

    scanf("%d", &t);

    while (t --) {
        scanf("%d %d", &e, &f);
        scanf("%d", &n);

        // ���ջ���
        coins = (coin *)malloc(sizeof(coin) * (n + 1));
        if (coins == NULL)  exit(-1);

        for (i = 1; i <= n; i ++) {
            scanf("%d %d", &coins[i].price, &coins[i].weight);
        }

        // ��ȫ����
        dynamicPackage(coins, n, f - e);


        free(coins);
        coins = NULL;
    }

    return 0;
}
