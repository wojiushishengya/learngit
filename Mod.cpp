#include<iostream>
using namespace std;
long int Mod(long int b,long int n,long int m);//���ؽ��Ϊb^n(mod m)
int main()//���Ժ���
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
