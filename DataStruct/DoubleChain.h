template <typename T>  /* ÉùÃ÷ÀàÄ£°å DoubleChain<T> */
class DoubleChain<T>;
template <typename T>
class DoubleChainNode
{
	friend class DoubleChain<T>;
private:
	T data;
	DoubleChainNode<T> *left, *right;
};
template <typename T>
class DoubleChain
{
public:
	DoubleChain() : leftEnd(nullptr), rightEnd(nullptr) {}
	~DoubleChain();
	int Length() const
	{

	}
private:
	DoubleNode<T> *leftEnd, *rightEnd;
};
