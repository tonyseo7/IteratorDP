#pragma once
#include "Arr.h"

class Tracer
{
public:

	void DoIt()
	{
		Arr<int> *arr = new Arr<int>(10);
		
		arr->Add(3);
		arr->Add(6);
		arr->Add(7);
		arr->Add(20);
		
		Iterator<int> *iter = arr->MakeIterator();
		iter->Begin();

		while (iter->MoveNext())
		{
			cout << iter->Current() << endl;
		}

		arr->RemoveIterator(iter);

		delete arr;
	}
};
