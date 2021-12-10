#include <iostream>
#include <stdio.h>
#include "TQueue.h"
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <random>
using namespace std;


int main()
{
	srand(time(0));
	double p, p1, q, q1, r;
	setlocale(LC_ALL, "Russian");
	cout << "Введите шанс добавления в очередь " << endl;
	cin >> p1;
	cout << "Введите шанс извлечения из очереди " << endl;
	cin >> q1;
	TQueue<int> que(10);



	cout << "Status: " << endl;
	cout << "Длина очереди:" <<que.GetLen()<< endl;
	cout << "Максимальный размер:" << que.GetMaxsize() << endl;
	cout << "------------------------------" << endl;
	
	for (int k = 1;; k++)
	{
		//r = (rand() % 100) + 1;
		r = rand() % (int)pow(10, 1);
		r = 0 + (r / pow(10, 1));

		cout << "------------ Итерация " << k << " ------------" << endl;
		cout << "INFO:" << endl;
		cout << "Сгенерировано случайное число " << r << endl;
		cout << "Шанс добавления в очередь: " << p1 << endl;
		cout << "Шанс извлечения из очереди: " << q1 << endl;   // Цвет! вывод новой очереди
		cout << endl;
		cout << "Action:" << endl;
		if (r <= p1)
		{
			if (!que.IsFull())
			{
				que.Push(1);
				cout << "Элемент добавлен" << endl;
			}
			else
			{
				cout << "Элемент не может быть добавлен" << endl;
				exit(0);
			}
		}
		if (r <= q1)
		{
			if (!que.IsEmpty())
			{
				que.Pop();
				cout << "Элемент извлечен" << endl;
			}
			else
			{
				cout << "Элемент не может быть извлечен" << endl;
				exit(0);
			}
		}
		cout << "------------------------------" << endl;
		cout << endl;
		cout << "Status:" << endl;
		cout << "Длина очереди: " << que.GetLen() << endl;
		cout << "Макс длина: " << que.GetMaxsize() << endl;
		cout << "----------------------------------" << endl;
		
		//getch();
	}
	return 0;


}
	//setlocale(LC_ALL, "Russian");
 //  TQueue<int> q(10);
 //  cout << "Status: "<<endl;
 //  cout << "Длина очереди:" <<q.GetLen()<< endl;
 //  q.Push(1);
 //  q.Push(2);
 //  q.Push(3);
 //  q.Push(4);
 //  cout << "------------------------------" << endl;
 //  cout << "Status: " << endl;
 //  cout << "Длина очереди:" << q.GetLen() << endl;
 //  cout << "Первый элемент: " <<q.TopHead()<< endl;
 //  cout << "Последний элемент: " << q.TopTail()<<endl;
 //  cout << "------------------------------" << endl;
 //  q.Pop();
 //  q.Pop();
 //  q.Push(5);
 //  cout << "Status: " << endl;
 //  cout << "Длина очереди:" << q.GetLen() << endl;
 //  cout << "Первый элемент: " << q.TopHead() << endl;
 //  cout << "Последний элемент: " << q.TopTail() << endl;


