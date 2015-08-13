/********************************
 * FileName:slist_test.cpp
 * Comment:test code for single linked list
 * Version:1.0
 * Author:wangxu
 * Date:2015-08-12
 * *****************************/
#include<iostream>
#include"slist.h"

using namespace std;
int main(){
	Slist<int>slist;
	int i=slist.size();
	cout<<i<<endl;
	
	slist.push_back(2);

	for(int j1=0;j1<slist.size();++j1)
		cout<<slist.value(j1+1)<<'-';
	cout<<endl;
	
	slist.push_front(4);
	for(int j2=0;j2<slist.size();++j2)
		cout<<slist.value(j2+1)<<'-';
	cout<<endl;

	slist.insert_after(7,1);
	i=slist.size();
	cout<<i<<endl;
	for(int j3=0;j3<slist.size();++j3)
		cout<<slist.value(j3+1)<<'-';
	cout<<endl;

	slist.reverse();
	cout<<slist.size()<<endl;
	for(int j4=0;j4<slist.size();++j4)
		cout<<slist.value(j4+1)<<'-';
	cout<<endl;
		i=slist.size();
	cout<<i<<endl;
	
	slist.clear();
	cout<<slist.size()<<endl;
	return 0;
}


 
