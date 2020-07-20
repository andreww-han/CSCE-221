#include <iostream>
#include "PriorityQueue.h"
#include "Stopwatch.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	StopWatch t;
	srand(time(0));
	UnsortedPriorityQueue<int> a;
	/*a.insertItem(7);
	a.insertItem(23);
	a.insertItem(9);
	a.insertItem(3);
	a.insertItem(12);
	a.insertItem(5);
	a.insertItem(2);
	a.insertItem(32);
	a.insertItem(6);
	a.insertItem(42);
	for (int i = 0; i < 10; i++)
	{
		cout << a.removeMin() << endl;
	}*/
	int n = 50;
	t.start();
	for (int i = 0; i < n; i++)
	{
		a.insertItem(rand());
	}
	for (int i = 0; i < n; i++)
	{
		cout << a.removeMin() << endl;
	}
	t.stop();
	cout << t.ms();
	return 0;
}