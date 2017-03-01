#include <iostream>
template <typename T>
class Chain;
template <class T>
class ChainNode
{
	friend class Chain<T>;
public:
	T getData() const
	{
		return data;
	}
	ChainNode<T> *getLink() const
	{
		return link;
	}
private:
	T data;
	ChainNode<T> *link;
};
template <class T>
class Chain
{
	//template <typename T>
	friend std::ostream& operator<<(std::ostream &os, const Chain<T> &item)
	{
		ChainNode<T> *now = item.first;
		while (now != nullptr)
		{
			os << now->getData() << " ";
			now = now->getLink();
		}
		return os;
	}
public:
	Chain() : first(nullptr) {}
	~Chain()
	{
		ChainNode<T> *next;
		while (first != nullptr)
		{
			next = first->link;
			delete first;
			first = next;
		}
	}
	bool isEmpty() const
	{
		return first == nullptr;
	}
	int Length() const
	{
		int length = 0;
		ChainNode<T> *now = first;
		while (now != nullptr)
		{
			++length;
			now = now->link;
		}
		return length;
	}
	bool Find(int k, T& x) const /* 将第k个元素保存到x中 */
	{
		if (k <= 0)
			return false;
		ChainNode<T> *now = first;
		while (now != nullptr && k != 1)
		{
			now = first->link;
			--k;
		}
		if (k == 1)  /* 存在第k个元素 */
		{
			x = now->data;
			return true;
		}
		else
			return false;
	}
	int Search(const T& x) const
	{
		int i = 1;
		ChainNode<T> *now = first;
		while (now != nullptr && (now->data) != x)
		{
			++i;
			now = now->link;
		}
		if (now == nullptr)
			return -1;
		else
			return i;
	}
	Chain<T>& Delete(int k, T& x)
	{
		if (k <= 0 || first == nullptr)
			return *this;
		ChainNode<T> *now = first;
		if (k == 1) /* 要删除的是第一个 */
		{
			first = now->link;
			x = now->data;
			delete now;
			return *this;
		}
		while (now != nullptr && k != 2)
		{
			now = first->link;
			--k;
		}
		if (k == 2)  /* 存在第k-1个元素，改变第k-1的link */
		{
			ChainNode<T> *temp = now->link;
			if (temp != nullptr)
			{
				now->link = temp->link;
				x = temp->data;
				delete temp;
				return *this;
			}
			else      /* 只存在第k-1个，不存在第k个 */
				return *this;
		}
		else        /* 不存在，删除失败 */
			return *this;
	}
	Chain<T>& Insert(int k, const T& x)  /* 在第k个元素之后插入x */
	{
		if (k < 0)
			return *this;
		if (k == 0)
		{
			ChainNode<T> *temp = new ChainNode<T>();
			temp->data = x;
			temp->link = nullptr;
			first = temp;
			return *this;
		}
		ChainNode<T> *now = first;
		while (now != nullptr && k != 1)
		{
			now = first->link;
			--k;
		}
		if (k == 1)   /* 存在第k个元素 */
		{
			ChainNode<T> *temp = new ChainNode<T>();
			temp->data = x;
			temp->link = now->link;
			now->link = temp;
			return *this;
		}
		else          /* 不存在第k个元素 */
			return *this;
	}
	void Output(std::ostream& os)
	{
		ChainNode<T> *now = first;
		while (now != nullptr)
		{
			os << now->data << " ";
			now = now->link;
		}
	}
private:
	ChainNode<T> *first;
};