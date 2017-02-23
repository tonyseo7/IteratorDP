#pragma once
#include "Collection.h"
#include "Iterator.h"

template <typename T>
class Arr : public Collection<T>
{
	T *base;
	const int max_capa;
	int cnt;
	friend class ArrIterator;

public:
	class ArrIterator : public Iterator<T>
	{
		Arr<T> *arr;
		int index;

	public:
		ArrIterator(Arr<T> *arr);
		virtual void Begin() { index = -1; }
		virtual bool MoveNext();
		virtual T Current() { return arr->base[index]; }

	};

public:
	Arr(int max_capa);
	~Arr();

	virtual bool Add(T t);
	virtual void Remove(T t);
	virtual void Clear() { cnt = 0; }
	virtual int Count() const { return cnt; }
	virtual Iterator<T> *MakeIterator();
	virtual void RemoveIterator(Iterator<T> *iter);

private:
	bool IsFull() const;
	int Find(T t);
	
};


template <typename T>
Arr<T>::Arr(int max_capa) :max_capa(max_capa)
{
	base = new T[max_capa];
	cnt = 0;
}


template <typename T>
Arr<T>::~Arr()
{
	delete[] base;
}

template <typename T>
Arr<T>::ArrIterator::ArrIterator(Arr<T> *arr)
{
	this->arr = arr;
	index = -1;
}

template <typename T>
bool Arr<T>::ArrIterator::MoveNext()
{
	index++;

	if (index < arr->cnt)
	{
		return true;
	}

	return false;

}



template <typename T>
bool Arr<T>::Add(T t)
{
	if (IsFull())
	{
		return false;
	}

	base[cnt] = t;
	cnt++;

	return true;
}

template <typename T>
void Arr<T>::Remove(T t)
{
	int index = Find(t);

	if (index = -1)
	{
		return;
	}

	for (; index < (cnt - 1); index++)
	{
		base[index] = base[index + 1];
	}

	cnt--;
}


template <typename T>
Iterator<T>* Arr<T>::MakeIterator()
{
	return new ArrIterator(this);
}


template <typename T>
void Arr<T>::RemoveIterator(Iterator<T> *iter)
{
	delete iter;
}


template <typename T>
bool Arr<T>::IsFull()const
{
	return cnt == max_capa;
}


template <typename T>
int Arr<T>::Find(T t)
{
	int index = 0;

	for (index = 0; index < cnt; index++)
	{
		if (base[index] == t)
		{
			return index;
		}
	}

	return -1;
}



