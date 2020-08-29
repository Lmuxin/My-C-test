#include<stdio.h>
#include<math.h>
int main()
{

    double dis(double x1,double y1,double x2,double y2);

  double x1, y1, x2, y2;
  printf("输入点的坐标\n");
  scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
printf("点之间的距离是：%lf",dis(x1,y1,x2,y2)); //这里是%lf,%d也错
  return 0;

}

double dis(double x1,double y1,double x2,double y2)
{

double d;
d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));//不能用（x1-x2)^2表示平方  编译不通过
   return d;

}



