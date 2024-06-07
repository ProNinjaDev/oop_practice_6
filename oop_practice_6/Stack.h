#include <iostream>
#include <cmath>
#include <locale.h>
#include "CustomError.h"

using namespace std;

template <typename T>
class Stack {
	T* m_array;
	int top;
	int m_capacity;

public:
	Stack(int capacity) {
		top = -1;
		m_capacity = capacity;
		m_array = new T[capacity];
	}

	void Push(const T value) {
		if (IsFull()) {
			int newCapacity = ceil(sqrt(2) * m_capacity);
			T* newStack = new T[newCapacity];

			for (int i = 0; i <= top; i++) 
				newStack[i] = m_array[i];

			delete[] m_array;
			m_array = newStack;
			m_capacity = newCapacity;
		}
		m_array[++top] = value;
	}

	T Pop() {
		if (top > -1) {
			top--;
			return m_array[top + 1];
		}
		else 
			throw CustomError("�������� �� ������� �����!");
	}

	T Peek() {
		if (top == -1)
			throw CustomError("������ �������� �� ������� �����!");
		else
			return m_array[top];
	}

	bool IsEmpty() {
		if (top > -1)
			return false;
		else
			return true;
	}

	bool IsFull() {
		if (top == m_capacity - 1)
			return true;
		else
			return false;
	}

	void Clear() {
		top = -1;
	}

	int GetCapacity() {
		return m_capacity;
	}

	int GetSize() {
		return top + 1;
	}
};


