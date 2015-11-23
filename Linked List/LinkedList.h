#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "p2Defs.h"

template <class TYPE>
class NodeList
{
	//Empty constructor
	NodeList(const TYPE& data) : data(data){}
	TYPE data = NULL;
private:
	NodeList<TYPE>* next = NULL;
};

template <class TYPE>
class LinkedList
{
public:
	NodeList<TYPE>* start = NULL;
	//Constructors & Destructors
	LinkedList(){}

	~LinkedList(){}

	//Methods
	NodeList<TYPE>* GetLast(){
			NodeList<TYPE>* tmp = start;
			while (tmp->next)
			{
				tmp = tmp->next;
			}

			return tmp;
		}

	void PushBack(const TYPE& n){
		NodeList<TYPE>* node = new NodeList<TYPE>(n);


		if (start == NULL)
			start = node;

		else{
			NodeList<TYPE>* tmp = GetLast();
			tmp->next = node;
			node->next = NULL;
		}

	}

	uint Size()const{
		NodeList<TYPE>* tmp = start;
		uint i = 0;
		while (tmp->next != NULL){
			tmp = tmp->next;
			++i;
		}
		return i;
	}

	void Clear(){
		NodeList<TYPE>* tmp = start;
		NodeList<TYPE>* Tmp2 = start;

		while (tmp)	{
			tmp2 = tmp;
			tmp = tmp->next;
			delete tmp2;
		}
		start = NULL;
	}

	bool Empty()const{
		return start == NULL;
	}


};

#endif