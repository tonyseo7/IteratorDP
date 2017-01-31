#pragma once
#include "common.h"

template <typename T>
class Collection
{
public:
	
	virtual bool Add(T t) = 0;
	virtual void Remove(T t) = 0;
	virtual void Clear() = 0;
	virtual int Count() const = 0;
	
};