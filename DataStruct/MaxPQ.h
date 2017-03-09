#ifndef MAXPQ

#define MAXPQ

/* 当一棵二叉树的每个结点都大于等于它的两个子节点时，它被称为堆有序 */
template <typename T>
class MaxPQ
{
private:
	T *pq;
	int n;
	void swim(int k)  /* 当某个结点变得比他的父节点更大时，需要浮（swim）上来 */
	{
		while (k > 1 && (pq[k / 2] < pq[k]))
		{
			int temp = pq[k / 2];
			pq[k / 2] = pq[k];
			pq[k] = temp;
			k /= 2;
		}
	}
	void sink(int k)  /* 当某个结点变得比它的两个子结点更小时，需要沉（sink）下去 */
	{
		while (2 * k < n)
		{
			int j = 2 * k;
			if (j < n && (pq[j] < pq[j + 1])) /* 找出两个子结点中较大的一个 */
				++j;
			if (pq[k] > pq[j])
				break;
			int temp = pq[k];
			pq[k] = pq[j];
			pq[j] = temp;
			k = j;
		}
	}
public:
	MaxPQ(int size) : n(0)
	{
		pq = new T[size];
	}
	~MaxPQ()
	{
		delete pq;
	}
	bool isEmpty()
	{
		return n == 0;
	}
	int size()
	{
		return n;
	}
	void insert(T v)
	{
		pq[++n] = v;
		swim(n);
	}
	T delMax()
	{
		T max = pq[1];
		pq[1] = pq[n--];
		sink(1);
		return max;
	}
	T * getPoin()
	{
		return pq;
	}
};
#endif // !MAXPQ

