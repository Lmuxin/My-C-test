
	//#include "stdafx.h"
	#include <iostream>
	using namespace std;

	const int L = 7;

	int LookupChain(int i,int j,int **m,int **s,int *p);
	int MemoizedMatrixChain(int n,int **m,int **s,int *p);

	void Traceback(int i,int j,int **s);//构造最优解

	int main()
	{
	    int p[L]={30,35,15,5,10,20,25};

	    int **s = new int *[L];
	    int **m = new int *[L];
	    for(int i=0;i<L;i++)
    {
	        s[i] = new int[L];
	        m[i] = new int[L];
	    }

	    cout<<"矩阵的最少计算次数为："<<MemoizedMatrixChain(6,m,s,p)<<endl;
	    cout<<"矩阵最优计算次序为："<<endl;
    Traceback(1,6,s);
	    return 0;
	}

	int MemoizedMatrixChain(int n,int **m,int **s,int *p)
	{
	    for(int i=1; i<=n; i++)
	    {
        for(int j=1; j<=n; j++)
	        {
	            m[i][j]=0;
	        }
	    }
	    return LookupChain(1,n,m,s,p);
	}

	int LookupChain(int i,int j,int **m,int **s,int *p)
	{
	    if(m[i][j]>0)
	    {
	        return m[i][j];
    }
    if(i==j)
	    {
	        return 0;
	    }

	    int u = LookupChain(i,i,m,s,p) + LookupChain(i+1,j,m,s,p)+p[i-1]*p[i]*p[j];
	    s[i][j]=i;
    for(int k=i+1; k<j; k++)
    {
	        int t = LookupChain(i,k,m,s,p) + LookupChain(k+1,j,m,s,p) + p[i-1]*p[k]*p[j];
	        if(t<u)
        {
	            u=t;
	            s[i][j] = k;
        }
	    }
	    m[i][j] = u;
    return u;
	}

	void Traceback(int i,int j,int **s)
{
    if(i==j) return;
	    Traceback(i,s[i][j],s);
	    Traceback(s[i][j]+1,j,s);
    cout<<"Multiply A"<<i<<","<<s[i][j];
	    cout<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
	}

