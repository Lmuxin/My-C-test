#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 #define  true   1
  #define  false  0
#define  N  30


  typedef struct {
      double data[N];
      int top;
  } Stack;




 void Push( Stack *ptr, double item )
{
     if( ptr->top == N - 1 ){
          printf( "Stack is full.\n" );
         return;
    } else {
         ptr->data[ ++( ptr->top ) ] = item;
        return;
      }
 }


 double Pop( Stack * ptr )
  {
      if( ptr->top == -1 ) {
        printf( "Stack is empty.\n" );
         return;
     } else
         return ptr->data[ ( ptr->top )-- ];
  }


int IsOperator( char ch )
 {
     if( ch == '+' || ch == '-' || ch == '*' || ch == '/' )
         return true;
     else
        return false ;
}


 double Calcu( double a, double b,char ch )
{
     switch( ch ) {
         case '+' : return a + b; break;
          case '-' : return a - b; break;
         case '*' : return a * b; break;
          case '/' : return a / b;
      }
  }

  int main()
  {
    char expr[N];
      gets( expr );
      int len = strlen( expr );

      Stack ss;

      ss.top = -1;

      double cc = 1;
      double tem_sum = 0;
      double oper_a;
      double oper_b;
      double result;
      int error = 0;
      int i;
      for( i = len - 1; i >= 0; -- i ) {
         if( expr[i] >= '0' && expr[i] <= '9' ) {
              tem_sum += ( expr[i] - '0' ) * cc;
              cc *= 10;
              if( expr[i-1] == '+' ) {

                  Push( &ss, tem_sum );
                  tem_sum = 0;
                  cc = 1;
                  i -= 2;
                  continue;
              } else if( expr[i-1] == '-' ) {
                  tem_sum = -tem_sum;

                 Push( &ss, tem_sum );
               tem_sum = 0;
                 i -= 2;
                 continue;
             } else if( expr[i-1] == ' ' ) {

                 Push( &ss, tem_sum );
               tem_sum = 0;
                cc = 1;
                i --;
                 continue;
             }
         } else if( expr[i] == '.' ) {
             tem_sum /= cc * 1.0;
             cc = 1;
        } else if( IsOperator( expr[i] ) ) {
            oper_a = Pop( &ss );
             oper_b = Pop( &ss );
            if( expr[i] == '/' && oper_b == 0 ) {
                error = 1;
                break;
            } else {
                result = Calcu( oper_a, oper_b, expr[i] );

                Push( &ss, result );
                 i--;
             }
         }
   }
    if( error != 1 )
         printf( "%.1lf\n", Pop( &ss ) );
    else
        printf( "error\n" );

     return 0;
}
