
#include<iostream>

using namespace std;
long int Mod(long int b,long int n,long int m);//����ֵ=b^n(mod m)
long int Findn(long int p);//�ҵ�һ��ģp��ƽ���ķǶ���ʣ��
long int Finda(long int a,long int p);//�ҵ�a����p����Ԫ
long int pows(long int a,long int b);//����a^b
void main(i)//����ģpƽ����
{
	long int a,p,t=1,s,b,a_1;//��p-1=2^t * s;
	
	cout<<"please input the a and p:";
	cin>>a>>p;
	long int temp=p-1;
	if(a<0 || p<0)
	{
		cerr<<"data error!"<<endl;
		exit(0);
	}
	if(Mod(a,(p-1)/2,p) == (p-1))
	{
			cout<<"ԭ�����޽�"<<endl;
			return;
	}
	for(;;t++)
	{
		long int temp1=pows(2,t);
		if(temp%temp1 !=0)
			break;
	}
	t--;
	s=(p-1)/pows(2,t);//�õ�s,t��ֵ
	b=Mod(Findn(p),s,p);
	a_1=Finda(a,p);
	long int x=Mod(a,(s+1)/2,p);//��
	for(int i=0;;i++,t--)
	{
		int j=2;
		if(t==1)
			break;
		else
		{
			if(Mod((a_1*x*x)%p,pows(2,t-2),p) == (p-1))
			{
				x=(x*Mod(b,pows(j,i),p))%p;
			
			}
		}
	}
	cout<<x<<endl;
	
	return;
}
long int Mod(long int b,long int n,long int m)
{
		int digit[32],i=0,j=0;//digit[32]�洢n�Ķ����Ʊ�ʾ��ʽ
		long int result=1;
		while(n)
		{
			digit[i++] = n%2;
			n=n>>1;//������һλ
		}
		for(j=0;j<=i;j++)
		{
			if(digit[j] == 1)
				result=(result*b)%m;
			b=(b*b)%m;
		}
		return result;
}
long int Findn(long int p)
{
	long int n=2;
	for(;n<p-1;n++)
	{
		//cout<<Mod(n,(p-1)/2,p)<<endl;
		if(Mod(n,(p-1)/2,p) == (p-1))
				break;
	}
	return n;
}
long int Finda(long int a,long int p)
{
	long int i=2;
	for(;i<=p-1;i++)
	{
		if(((a*i)%p) == 1)
				break;
	}
	return i;
}
long int pows(long int a,long int b)
{
	long int sum=1;
	if(b==0)
		return sum;
	else
	{
		for(long int i=1;i<=b;i++)
		{
			sum=sum*a;
		}
		return sum;
	}
}
