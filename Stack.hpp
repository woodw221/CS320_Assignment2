#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <iostream>

template <class T>
class Stack
{
	private:
		std::vector<T> realStack;
		int top;

	public:
		Stack();
		void Push(T);
		void Pop();
		void Print();
};


template <class T>
Stack<T>::Stack()
{
    this->top = -1;
}

template <class T>
void Stack<T>::Push(T input)
{
	realStack.push_back(input);
	top++;
}

template <class T>
void Stack<T>::Pop()
{
	if(top == -1)
	{
		std::cout << "Stack Empty!";
	}
	else
	{
		realStack.pop_back();
		top--;
	}
}

template <class T>
void Stack<T>::Print()
{
	int i = 0;
	std::cout << "[";
	while(i <= top)
	{
		std::cout << ' ' << realStack[i];
		i++;
	}
	std::cout << " ]\n";
	
}


#endif
