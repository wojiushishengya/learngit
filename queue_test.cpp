/***************************************
 * FileName:queue_test.cpp
 * Comment:queue implemented in terms of single linked list
 * Version:1.0
 * Author:wangxu
 * Date:2015-08-13
 * *************************************/
#include<iostream>
#include"queue.h"
using namespace std;

int main(){
	Queue<int> queue;
	queue.en_queue(3);
	queue.en_queue(6);
	queue.en_queue(11);
	queue.de_queue(); 

	int num=queue.size();
	for(int i=0;i!=num;++i)
		cout<<queue.de_queue()<<'-';
	cout<<endl;
	return 0;
}
