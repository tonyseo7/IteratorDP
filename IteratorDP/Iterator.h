#pragma once

template <typename T>

class Iterator
{
public:
	virtual void Begin() = 0;
	virtual bool MoveNext() = 0;
	virtual T Current() = 0;
};
