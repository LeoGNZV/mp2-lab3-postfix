#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
	T* pMem;
	int size;
	int top;
public:
	TStack(int _size)
	{
		size = _size;
		top = -1;
		if ((size < 1) || (size > MaxStackSize))
			throw "Invalid stack size";
		pMem = new T[size];
	}
	void push(T val)
	{
		if (top >= size - 1)
		{
			if (size * 2 > MaxStackSize)
				throw "Stack size is too large";
			T* tmppMem = new T[size * 2];
			std::copy(pMem, pMem + size, tmppMem);
			delete[] pMem;
			pMem = tmppMem;
			size *= 2;
		}
		pMem[++top] = val;
	};
	T pop()
	{
		if (empty())
			throw "The stack is over";
		return pMem[top--];
	};
	bool empty()
	{
		return (top < 0);
	}
	~TStack()
	{
		delete[] pMem;
	}
};

#endif
