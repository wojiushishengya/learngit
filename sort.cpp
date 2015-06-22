#include<iostream>
using namespace std;
typedef int Elementype;

void SelectSort(Elementype *p,int number);//选择排序(p为指向元素的指针，number为该数组中元素的个数)
void Sift(Elementype *p,int k,int m);//堆排序辅助函数, 假设p[k+1,...m]中各元素满足堆的性质,本函数调整p[k]使整个序列p[k,...m]中各元素满足堆得性质
void HeapSort(Elementype *p,int number);//堆排序主体函数(p为指向元素的指针，number为该数组中元素的个数)
void BubbleSort(Elementype *p,int number);//冒泡排序（p为指向元素的指针,number为该数组中元素的个数)
int Qkpass(Elementype *p,int s,int t);/*快速排序辅助函数,本函数对p[s...t]中的元素进行一趟快速排序,执行此函数后,
求得i(s<=i<=t),若s<i,则p[s...i-1]中的元素均不大于p[i],若i<t,则p[i+1...t]中的元素均不小于p[i],函数返回值为i*/
void QuickSort(Elementype *p,int s,int t);//s,t为该数组中起始元素和终止元素的下标
void Merge(Elementype *p,int l,int m,int n,Elementype *temp);//归并排序的辅助函数已知p[l...m]和p[m+1...n]分别有序，本函数将它们归并成一个有序序列并放在temp[l...n]中 
void MergeSort(Elementype *p,Elementype * t,int s,int t1);//归并排序，本函数对p[s...t1]中的元素进行2路归并排序，是p[s...t1]中元素有序 
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
		/*筛选时总是将根节点和左右孩子中最小的交换*/
		if((j<m) && (p[j]>p[j+1]))//若存在右子树,且右子树的关键字小,则沿右分支“筛选”
			j++;
		if(p[0]<=p[j])//若满足则筛选结束
			finished=true;
		else//否则将根节点和左右孩子中小的交换
		{
			p[i]=p[j];//p[i]的值在x中保存
			i=j;//交换后再次检查
			j=2*i;
		}
	}
	p[i]=p[0];
}
void HeapSort(Elementype *p,int number)
{
	/*建堆*/
	for(int i=number/2;i>=1;i--)//将p的序列看成完全二叉树,那么最后一个非终端节点是第（n/2）下取整，故从此处开始筛选
		Sift(p,i,number);
	/*对p[1...n]进行堆排序,执行本算法后,p中元素按从大到小有序排列*/
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
		sorted=true;//现将soered置为真,若在一趟冒泡中未发生任何交换，则说明该序列已有顺序
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
	int j=t;//i,j表示初始搜索位置,当两者相等时表示一趟快排结束
	p[0]=p[i];//p[0]中存放本次要排序的数,及枢轴元素
	while(i<j)
	{
		while((i<j) && (p[j]>=p[0]))
			j=j-1;
		p[i]=p[j];//找到p[i]<枢轴元素
		while((i<j) && (p[i]<=p[0]))
			i=i+1;
		p[j]=p[i];//找到p[j]>枢轴元素
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
	int i=l;//第一个序列的开始 
	int j=m+1;//第二个序列的开始 
	int k=l-1;//辅助数组temp的开始
	while((i<=m) && (j<=n))//两个序列都不超过下线
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
	if(i<=m)//如第一个序列有剩余
		for(k=k+1;i<=m;i++,k++)//将剩余元素复制到temp中 
			temp[k]=p[i];	
	if(j<=n)//如果第二个序列有剩余
		for(k=k+1;j<=n;j++,k++)//将剩余元素复制到temp中 
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
	
