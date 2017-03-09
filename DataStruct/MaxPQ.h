#ifndef MAXPQ

#define MAXPQ

/* ��һ�ö�������ÿ����㶼���ڵ������������ӽڵ�ʱ��������Ϊ������ */
template <typename T>
class MaxPQ
{
private:
	T *pq;
	int n;
	void swim(int k)  /* ��ĳ������ñ����ĸ��ڵ����ʱ����Ҫ����swim������ */
	{
		while (k > 1 && (pq[k / 2] < pq[k]))
		{
			int temp = pq[k / 2];
			pq[k / 2] = pq[k];
			pq[k] = temp;
			k /= 2;
		}
	}
	void sink(int k)  /* ��ĳ������ñ����������ӽ���Сʱ����Ҫ����sink����ȥ */
	{
		while (2 * k < n)
		{
			int j = 2 * k;
			if (j < n && (pq[j] < pq[j + 1])) /* �ҳ������ӽ���нϴ��һ�� */
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

