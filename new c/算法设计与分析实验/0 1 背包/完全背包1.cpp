#include <iostream>
 using namespace std ;
 const  int V = 1000 ;  //�ܵ����
 const  int T = 5 ;    //��Ʒ������
 int f[V+1] ;
 #define EMPTY                                      //���Բ�װ��
 int w[T] = {8 , 10 , 4 , 5 , 5};        //��ֵ
 int c[T] = {500 , 600 , 400 , 400 , 400};        //ÿһ�������
 const int INF = -66536  ;

 int package()
 {
 //#ifdef EMPTY
    for(int i = 0 ; i <= V ;i++) //�������룬��ʾ�������Բ��洢��
      f[i] = 0 ;
 /*#else
    f[0] = 0 ;
    for(int i = 1 ; i <= V ;i++)//�������룬��ʾ��������ȫ���洢��
      f[i] = INF ;
 #endif
 */
    for(int i = 0 ; i < T ; i++)
    {
      for(int v = c[i] ; v <= V ;v++)               //����ȫ����V�ݼ���0
         {
            f[v] = max(f[v-c[i]] + w[i] , f[v])  ; //��f[v]ʵ�����Ǳ�ʾ����i-1��֮ǰ��ֵ��
         }
    }
    return f[V] ;
 }

 int main()
 {

   int temp = package() ;
   cout<<temp<<endl     ;
   //system("pause")      ;
   return 0 ;
 }
