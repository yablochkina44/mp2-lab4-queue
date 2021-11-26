#pragma once
#include <iostream>
using namespace std;

template <class T>
class TQueue
{
	T* mas;		    //массив очереди
	int maxsize;	//размер массива очереди
	int head;		//голова очереди
	int tail;		//хвост очереди
	int len;		//длина очереди
public:
	TQueue(int m = 10);
	TQueue(const TQueue& Q);
	~TQueue<T>() { delete[] mas; }

	bool IsEmpty();       // проверка на пустоту
	bool IsFull();        // Проверка на полноту
	void Push(T n);		  // Добавить элемент в очередь
	T Pop();              // Извлечь элемент из очереди
	T TopHead();		  //Посмотреть начало очереди
	T TopTail();		  //Посмотреть конец очереди

	int GetMaxsize() { return maxsize; }
	int GetLen() { return len; }

};

template <class T>
TQueue<T>::TQueue(int m)
{
	maxsize = m;
	mas = new T[maxsize];
	head = 0;
	tail = -1;
	len = 0;
}
template <class T>
TQueue<T>::TQueue(const TQueue& с)
{
	maxsize = с.maxsize;
	mas = new T[maxsize];
	for (int i = 0; i < maxsize; i++)
		mas[i] = с.mas[i];
	head = с.head;
	tail = с.tail;
	len = с.len;
}
template <class T>
bool TQueue<T>::IsEmpty()
{
	if (len == 0)
		return true;
	return false;
}
template <class T>
bool TQueue<T>::IsFull()
{
	if (len == maxsize)
		return true;
	return false;
}
template <class T>
void TQueue<T>::Push(T n)
{
	tail = (tail + 1) % maxsize;
	mas[tail] = n;
	len++;
}
template <class T>
T TQueue<T>::Pop()
{
	if (IsEmpty())
		throw - 1;
	else
	{

		T tmp = mas[head];
		head++;
		len--;
		return tmp;
	}
}
template<class T>
T TQueue<T>::TopHead()
{
	if (IsEmpty())
		throw - 1;
	else
	{
		return mas[head];
	}
}
template<class T>
T TQueue<T>::TopTail()
{
	if (IsEmpty())
		throw - 1;
	else
	{
		return mas[tail];
	}
}

