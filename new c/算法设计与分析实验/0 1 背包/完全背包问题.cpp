#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
/*
f[v]:��ʾ��i����Ʒ��������Ϊv�ı����󣬻�õ��������
f[v] = max(f[v],f[v - weight[i]] + value[i]);
��ʼ������f[0] = 0;
*/

const int N = 3;
const int V = 20;//5
int weight[N + 1] = {0,3,2,2};
int Value[N + 1] = {0,5,10,20};

int NNew = 0;
vector<int> weightVector;
vector<int> Valuevector;
int f[V + 1] = {0};
/*�����Ʒ*/
void SplitItem()
{
    //��1��ʼ
    weightVector.push_back(0);
    Valuevector.push_back(0);
    //��ʼ���
    int nPower = 1;
    for (int i = 1;i <= N;i++)
    {
        nPower = 1;
        while (nPower * weight[i] <= V)
        {
            weightVector.push_back(nPower * weight[i]);
            Valuevector.push_back(nPower * Value[i]);
            nPower <<= 1;
        }
    }
}

int Completeknapsack()
{
    //�����Ʒ
    SplitItem();
    //ת��Ϊ01��������
    NNew = weightVector.size() - 1;//�����һ��0��Ҫ��ȥ

    for (int i = 1;i <= NNew;i++)//��Ʒ�����仯
    {
        for (int v = V;v >= weightVector[i];v--)//������������V
        {
            f[v] = max(f[v],f[v - weightVector[i]] + Valuevector[i]);
        }
    }

    return f[NNew];
}
int main()
{
    cout<<Completeknapsack()<<endl;
//    system("pause");
    return 1;
}
