#include<stdio.h>
#include<math.h>
int main()
{

    double dis(double x1,double y1,double x2,double y2);

  double x1, y1, x2, y2;
  printf("����������\n");
  scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
printf("��֮��ľ����ǣ�%lf",dis(x1,y1,x2,y2)); //������%lf,%dҲ��
  return 0;

}

double dis(double x1,double y1,double x2,double y2)
{

double d;
d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));//�����ã�x1-x2)^2��ʾƽ��  ���벻ͨ��
   return d;

}



