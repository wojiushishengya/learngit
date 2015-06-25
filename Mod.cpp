#include<iostream>
using namespace std;
long int Mod(long int b,long int n,long int m);//返回结果为b^n(mod m)
int main()//测试函数
{
	long int number;
	cout<<"please input a number!\n";
	cin>>number;
	for(long int i=2;i<number;i++)
	{
		if((i%10)==0)
			cout<<endl;
		cout<<Mod(i,number-1,number)<<'\t';
	}
	return 0;
}
long int Mod(long int b,long int n,long int m)
{
		int digit[32],i=0,j=0;//digit[32]存储n的二进制表示形式
		long int result=1;
		while(n)
		{
			digit[i++] = n%2;
			n=n>>1;//将右移一位
		}
		for(j=0;j<=i;j++)
		{
			if(digit[j] == 1)
				result=(result*b)%m;
			b=(b*b)%m;
		}
		return result;
}
