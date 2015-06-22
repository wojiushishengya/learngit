#include<iostream>
using namespace std;
typedef int Elementype;

void SelectSort(Elementype *p,int number);//ѡ������(pΪָ��Ԫ�ص�ָ�룬numberΪ��������Ԫ�صĸ���)
void Sift(Elementype *p,int k,int m);//������������, ����p[k+1,...m]�и�Ԫ������ѵ�����,����������p[k]ʹ��������p[k,...m]�и�Ԫ������ѵ�����
void HeapSort(Elementype *p,int number);//���������庯��(pΪָ��Ԫ�ص�ָ�룬numberΪ��������Ԫ�صĸ���)
void BubbleSort(Elementype *p,int number);//ð������pΪָ��Ԫ�ص�ָ��,numberΪ��������Ԫ�صĸ���)
int Qkpass(Elementype *p,int s,int t);/*��������������,��������p[s...t]�е�Ԫ�ؽ���һ�˿�������,ִ�д˺�����,
���i(s<=i<=t),��s<i,��p[s...i-1]�е�Ԫ�ؾ�������p[i],��i<t,��p[i+1...t]�е�Ԫ�ؾ���С��p[i],��������ֵΪi*/
void QuickSort(Elementype *p,int s,int t);//s,tΪ����������ʼԪ�غ���ֹԪ�ص��±�
void Merge(Elementype *p,int l,int m,int n,Elementype *temp);//�鲢����ĸ���������֪p[l...m]��p[m+1...n]�ֱ����򣬱����������ǹ鲢��һ���������в�����temp[l...n]�� 
void MergeSort(Elementype *p,Elementype * t,int s,int t1);//�鲢���򣬱�������p[s...t1]�е�Ԫ�ؽ���2·�鲢������p[s...t1]��Ԫ������ 
int main()
{
	Elementype a[10];
	cout<<"please input 9 number!"<<endl;
	for(int i=1;i<10;i++)
		cin>>a[i];
	SelectSort(a,9);
	for(int i=1;i<10;i++)
		cout<<a[i]<<'\t';
	cout<<endl;
	HeapSort(a,9);
	for(int i=1;i<10;i++)
		cout<<a[i]<<'\t';
	cout<<endl;
	BubbleSort(a,9);
	for(int i=1;i<10;i++)
		cout<<a[i]<<'\t';
	cout<<endl;
		QuickSort(a,1,9);
	for(int i=1;i<10;i++)
		cout<<a[i]<<'\t';
	cout<<endl;
	Elementype temp[10];
		MergeSort(a,temp,1,9);
	for(int i=1;i<10;i++)
		cout<<temp[i]<<'\t';
	cout<<endl;
	return 0;
}
void SelectSort(Elementype *p,int number)
{
	int i,j,smellpos;
	Elementype smellest;
	for(i=1;i<=number;i++)
	{
		smellest=p[i];
		smellpos=i;
		for(j=i+1;j<=number;j++)
		{
			if(smellest>p[j])
			{
				smellest=p[j];
				smellpos=j;
			}
		}
		if(smellest !=p[i])
		{
			p[smellpos]=p[i];
			p[i]=smellest;
		}
	}
}
void Sift(Elementype *p,int k,int m)
{
	int i=k,j=2*i;
	//Elementype x=p[k];
	p[0]=p[k];
	bool finished=false;
	while((j<=m) &&(!finished))
	{
		/*ɸѡʱ���ǽ����ڵ�����Һ�������С�Ľ���*/
		if((j<m) && (p[j]>p[j+1]))//������������,���������Ĺؼ���С,�����ҷ�֧��ɸѡ��
			j++;
		if(p[0]<=p[j])//��������ɸѡ����
			finished=true;
		else//���򽫸��ڵ�����Һ�����С�Ľ���
		{
			p[i]=p[j];//p[i]��ֵ��x�б���
			i=j;//�������ٴμ��
			j=2*i;
		}
	}
	p[i]=p[0];
}
void HeapSort(Elementype *p,int number)
{
	/*����*/
	for(int i=number/2;i>=1;i--)//��p�����п�����ȫ������,��ô���һ�����ն˽ڵ��ǵڣ�n/2����ȡ�����ʴӴ˴���ʼɸѡ
		Sift(p,i,number);
	/*��p[1...n]���ж�����,ִ�б��㷨��,p��Ԫ�ذ��Ӵ�С��������*/
	for(int i=number;i>=2;i--)
	{
		//Elementype temp;
		//temp=p[1];
		p[0]=p[1];
		p[1]=p[i];
		p[i]=p[0];
		Sift(p,1,i-1);
	}
	
}
void BubbleSort(Elementype *p,int number)
{
	bool sorted = false;
	int pass=0;
	while(!sorted)
	{
		pass++;
		sorted=true;//�ֽ�soered��Ϊ��,����һ��ð����δ�����κν�������˵������������˳��
		for(int i=1;i<=number-pass;i++)
			if(p[i]>p[i+1])
			{
				p[0]=p[i];
				p[i]=p[i+1];
				p[i+1]=p[0];
				sorted=false;
			}
	}
}
int Qkpass(Elementype *p,int s,int t)
{
	int i=s;
	int j=t;//i,j��ʾ��ʼ����λ��,���������ʱ��ʾһ�˿��Ž���
	p[0]=p[i];//p[0]�д�ű���Ҫ�������,������Ԫ��
	while(i<j)
	{
		while((i<j) && (p[j]>=p[0]))
			j=j-1;
		p[i]=p[j];//�ҵ�p[i]<����Ԫ��
		while((i<j) && (p[i]<=p[0]))
			i=i+1;
		p[j]=p[i];//�ҵ�p[j]>����Ԫ��
	}
	p[i]=p[0];
	return i;
}
void QuickSort(Elementype *p,int s,int t)
{
	int LowPosition;
	if(s<t)
	{
		LowPosition=Qkpass(p,s,t);
		QuickSort(p,s,LowPosition-1);
		QuickSort(p,LowPosition+1,t); 
	}
}
void Merge(Elementype *p,int l,int m,int n,Elementype *temp)
{
	int i=l;//��һ�����еĿ�ʼ 
	int j=m+1;//�ڶ������еĿ�ʼ 
	int k=l-1;//��������temp�Ŀ�ʼ
	while((i<=m) && (j<=n))//�������ж�����������
	{
		k=k+1;
		if(p[i] <=p[j])
		{
			temp[k]=p[i];
			i=i+1;
		}
		else
		{
			temp[k]=p[j];
			j=j+1;
		}
	} 
	if(i<=m)//���һ��������ʣ��
		for(k=k+1;i<=m;i++,k++)//��ʣ��Ԫ�ظ��Ƶ�temp�� 
			temp[k]=p[i];	
	if(j<=n)//����ڶ���������ʣ��
		for(k=k+1;j<=n;j++,k++)//��ʣ��Ԫ�ظ��Ƶ�temp�� 
			temp[k]=p[j]; 
}
void MergeSort(Elementype *p,Elementype * t,int s,int t1)
{
	if(s==t1)
		t[s]=p[s];
	else
	{
		MergeSort(p,t,s,(s+t1)/2);
		MergeSort(p,t,(s+t1)/2+1,t1);
		Merge(p,s,(s+t1)/2,t1,t);
	}
}
	
