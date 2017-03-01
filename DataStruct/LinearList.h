#include <iostream>
#include <cassert>
template<class T>
class LinearList
{
	template<typename T>
	friend std::ostream& operator<<(std::ostream &os, const LinearList<T> &item)
	{
		for (int i = 0; i < item.length; ++i)
			os << item.element[i] << " ";
		return os;
	}
public:
	LinearList() : length(0), capacity(2)
	{
		element = new T[2];
	}
	~LinearList()
	{
		delete[] element;
	}
	bool isEmpty() const
	{
		return length == 0;
	}
	int getLength() const  /* O(1) */
	{
		return length;
	}
	bool find(int k, T& x) const /* ����k��Ԫ�ظ�ֵ��x */  /* O(1) */
	{
		if (k > length || k < 1)
			return false;
		x = element[k - 1];
		return true;
	}
	int Search(const T& x) const  /* O(n) */
	{
		for (int i = 0; i < length; ++i)
			if (element[i] == x)
				return i + 1;
		return -1;
	}
	LinearList<T>& Delete(int k, T& x) /* ɾ����k��Ԫ�ز�����������x�� */
	{
		if (k > length || k <= 0)
			return *this;
		x = element[k - 1];
		--length;
		if (length <= capacity / 4)
		{
			element = fit(k);
			capacity = length;
			return *this;
		}
		for (int i = k - 1; i <  length; ++i)
		{
			element[i] = element[i + 1];
		}
		return *this;
	}
	LinearList<T>& Insert(int k, const T& x)
	{
		if (k > length || k < 0)
			return *this;
		if (length == capacity) /* ��Ҫ�����ڴ���� */
		{
			T * temp = new T[2 * length];
			capacity = 2 * length;
			for (int i = 0; i < k; ++i)
				temp[i] = element[i];
			temp[k] = x;
			if (k < length)
			{
				for (int i = length - 1; i >= k; --i)
					temp[i + 1] = element[i];
			}
			++length;
			element = temp;
			return *this;
		}
		/* ���������ڴ���� */
		/* ������Ƴ�λ�ã�Ȼ����� */
		for (int i = length - 1; i >= k; --i)
		{
			element[i + 1] = element[i];
		}
		element[k] = x;
		++length;
		return *this;	
	}
	void output(std::ostream &os)
	{
		for (int i = 0; i < length; ++i)
		{
			os << element[i] << " ";
		}
		os << std::endl;
	}
private:
	int length;
	int capacity;
	T *element;
	T * fit(int k)  /* ��ռ�ÿռ���С����ɾ����k��Ԫ�� */
	{
		std::cout << "auto shrink to fit" << std::endl;
		T * temp = new T[length]; 
		if (k > length)  /* Ҫɾ����Ԫ�����������һ�� */
		{
			for (int i = 0; i < length; ++i)
				temp[i] = element[i];
			delete[] element;
			element = temp;
			return element;
		}
		/* Ҫɾ����Ԫ�����м� */
		for (int i = 0; i < k - 1; ++i)
			temp[i] = element[i];
		for (int i = k; k < length; ++i)
			temp[i - 1] = element[i];
		delete[] element;
		element = temp;
		return element;
	}		
};