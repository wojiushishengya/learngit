/************************************
 * FileName:slist.h
 * Comment:single linked list(带表头的单向列表，基于单向链表)
 * Version:1.0
 * Author:wangxu
 * Date:2015-08-12
 * **********************************/
#ifndef _SLIST_H_INCLUDED
#define _SLIST_H_INCLUDED

#include<cassert>

template<typename T>
struct Slist_node{//节点类模板
	T element;
	Slist_node* next;
	Slist_node():element(),next(0){}
	explicit Slist_node(const T& elem):element(elem),next(0){}
	~Slist_node(){next=0;}
};

template<typename T>
class Slist{
	typedef Slist_node<T>*Ptrn;
public:
	/********************************
	 * 公有方法介绍
	 * empty():	判断该列表是否为空
	 * size():	返回该列表的节点数（不包括表头节点）
	 * reverse():	反转该列表
	 * *****************************/
	Slist():hb_head(new Slist_node<T>),hb_size(0){}
	~Slist();
	bool empty()const{return hb_size? false:true;}
	int size()const{return hb_size;}
	void reverse();
	
	/*******************************
	 * value():	返回给定号节点的元素
	 * push_front():在该列表前增加一个元素
	 * pop_front():	在该列表前删除一个元素,并输出删除的元素
	 * push_back():	在该列表后增加一个元素
	 * pop_back():	在该列表后删除一个元素,并输出删除的元素
	 * ****************************/
	T value(int pos)const;
	void push_front(const T& elem);
	T pop_front();
	void push_back(const T& elem);
	T pop_back();

	/********************************
	 * insert_after():	在给定节点后插入一个节点
	 * erase():		删除指定节点的元素
	 * erase():		删除列表中指定范围的节点
	 * clear():		删除列表
	 * *****************************/
	void insert_after(const T& elem,int pos);

	T erase(int pos);
	void erase(int beg,int end);
	void clear();

private:
	Slist_node<T>* hb_head;
	int hb_size;
};

template<typename T>
Slist<T>::~Slist(){
	clear();
	delete hb_head;
}
template<typename T>
void Slist<T>::clear(){//清空列表
	if(hb_size!=0)//若列表非空则调用erase函数
		erase(1,hb_size);
}
template<typename T>
 void Slist<T>::erase(int beg,int end){//删除该列表中从beg号开始到end号结束的所有节点(包括beg号节点)
	if(beg>hb_size || end>hb_size || beg<=0 || end<=0 || beg>end)
		std::cerr<<"error:position out of range!\n";
	else{
		Ptrn ptr=hb_head;
		Ptrn prev=0;//保留前一个元素的指针
		int i=0;
		while(i!=beg){
			prev=ptr;
			ptr=ptr->next;
			++i;
		}
		while(i<=end){
			Ptrn ptm=ptr;
			ptr=ptr->next;
			delete ptm;
			--hb_size;
			++i;
		}
		prev->next=ptr;//将end后的元素重新连上
	}
}
template<typename T>
T Slist<T>::erase(int pos){//删除pos号节点,并返回pos号节点的元素值
	assert(pos<=hb_size && pos!=0);//判断pos是否满足条件,并返回错误信息
	Ptrn ptr=hb_head;
	Ptrn prev=0;
	int i=0;
	while(i!=pos){
		prev=ptr;
		ptr=ptr->next;
		++i;
	}
	T t=ptr->element;
	prev->next=ptr->next;
	delete ptr;
	--hb_size;
	return t;
}
template<typename T>
void Slist<T>::insert_after(const T& elem,int pos){//在pos号节点后插入一个节点
	Ptrn ptr=hb_head;
	int i=0;
	while(i!=pos){
		ptr=ptr->next;
		++i;
	}
	Slist_node<T>*pSln=new Slist_node<T>;
	pSln->element=elem;
	pSln->next=ptr->next;
	ptr->next=pSln;
	++hb_size;
}
template<typename T>
void Slist<T>::push_front(const T& elem){//在该带表头节点的列表前增加一个节点
	insert_after(elem,0);
}
template<typename T>
void Slist<T>::push_back(const T& elem){//在该带表头节点的列表后增加一个节点
	insert_after(elem,hb_size);
}
template<typename T>
T Slist<T>::pop_front(){//在带表头节点的列表前删除一个节点,并显示删除的节点内容
	return erase(1);
}
template<typename T>
T Slist<T>::pop_back(){//在带表头节点的列表后删除一个节点,并显示删除节点的内容
	return erase(hb_size);
}
template<typename T>
inline T Slist<T>::value(int pos)const{//获取pos节点的内容
	Ptrn ptr=hb_head;
	int i=0;
	while(i!=pos){
		ptr=ptr->next;
		++i;
	}
	return ptr->element;
}
template<typename T>
void Slist<T>::reverse(){//反置列表
	Ptrn pbeg=hb_head->next;
	hb_head->next=0;//使得列表尾指针为空 
	hb_size=0;
	Ptrn ptr=pbeg;
	while(ptr!=0){
		push_front(ptr->element);//将列表中后一个节点插到前一个节点前面
		Ptrn ptm=ptr;
		ptr=ptr->next;
		delete ptm;//释放当前指针 
	}
}
#endif


