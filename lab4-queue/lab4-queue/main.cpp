#include <iostream>
#include "TQueue.h"
using namespace std;


void  main()
{

	setlocale(LC_ALL, "Russian");
   TQueue<int> q(10);
   cout << "Status: "<<endl;
   cout << "Длина очереди:" <<q.GetLen()<< endl;
   q.Push(1);
   q.Push(2);
   q.Push(3);
   q.Push(4);
   cout << "------------------------------" << endl;
   cout << "Status: " << endl;
   cout << "Длина очереди:" << q.GetLen() << endl;
   cout << "Первый элемент: " <<q.TopHead()<< endl;
   cout << "Последний элемент: " << q.TopTail()<<endl;
   cout << "------------------------------" << endl;
   q.Pop();
   q.Pop();
   q.Push(5);
   cout << "Status: " << endl;
   cout << "Длина очереди:" << q.GetLen() << endl;
   cout << "Первый элемент: " << q.TopHead() << endl;
   cout << "Последний элемент: " << q.TopTail() << endl;

}
