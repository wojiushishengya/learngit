/*****************************
 * FileName:queue.h
 * Comment:queue implemented in terms of single linked list
 * Version:1.0
 * Author:wangxu
 * Date:2015-08-13
 * **************************/
#ifndef _QUEUE_H_INCLUDED
#define _QUEUE_H_INCLUDED
#include"slist.h"
template<typename T>
class Queue{
	public:
		Queue():hb_slist(){}
		~Queue(){}

		bool empty()const{return hb_slist.empty();}
		void clear(){hb_slist.clear();}
		int size()const{return hb_slist.size();}
		void en_queue(const T& elem){//元素入队
			hb_slist.push_back(elem);
		}
		T de_queue(){//元素出队
			return hb_slist.pop_front();
		}
		T front()const{return hb_slist.value(1);}//返回队首元素
		T back()const{return hb_slist.value(hb_slist.size());}//返回队尾元素
	private:
		Slist<T>hb_slist;
};
#endif
