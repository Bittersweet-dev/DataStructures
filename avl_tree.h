#pragma once


template <typename T>
class NodeAVL
{
public:
	T data;
	class NodeAVL<T> * l;
	class NodeAVL<T> * r;

	NodeAVL() : l(NULL), r(NULL) {}
	NodeAVL(T data) : data(data), l(NULL), r(NULL) {}
};

template <typename T>
class treeAVL
{
public:
	NodeAVL<T> * root;

	treeAVL() : root(NULL) {}
	~treeAVL() { _Delete(root); }

public:
	int GetHeight(NodeAVL<T> * pNode)
	{
		int h = 0;
		if(pNode != NULL)
		{
			// 재귀적으로 왼쪽 혹은 오른쪽으로 검색합니다. 
			int left = GetHeight(pNode->l);
			int right = GetHeight(pNode->r);
			int maxHeight = left < right ? left : right;
			h = maxHeight + 1;
		}
		return h;
	}
	int GetDiff(NodeAVL<T> * pNode)
	{
		// 왼쪽 자식의 높이와 오른쪽 자식의 높이 차이를 반환합니다. 
		int left = GetHeight(pNode->l);
		int right = GetHeight(pNode->r);
		int factor = left - right;
		return factor;
	}
	void Insert(T data)
	{
		root = _Insert(root, data);
	}

private:
	NodeAVL<T> * _Insert(NodeAVL<T> * node, T & data)
	{
		// 현재 트리가 비었을 때 
		if(node == NULL)
		{
			node = new NodeAVL<T>(data);
			return node;
		}
		else if(data < node->data)
		{
			node->l = _Insert(node->l, data);
			node = _Balance(node);
		}
		else if(node->data <= data)
		{
			node->r = _Insert(node->r, data);
			node = _Balance(node);
		}
		return node;
	}
	NodeAVL<T> * _Balance(NodeAVL<T> * node)
	{
		int factor = GetDiff(node);
		// 왼쪽 서브트리쪽으로 삽입이 되어 균형이 깨진 경우입니다. 
		if(factor > 1)
		{
			// 그 왼쪽 자식노드에 문제가 발생했습니다. 
			if(GetDiff(node->l) > 0) node = ll(node);
			// 그 오른쪽 자식 노드에 문제가 발생했습니다. 
			else node = lr(node);
		}
		else if(factor < -1)
		{
			if(GetDiff(node->r) > 0) node = rl(node);
			else node = rr(node);
		}
		return node;
	}
	NodeAVL<T> * rr(NodeAVL<T> * parent)
	{
		// 말이 회전이지 그냥 부모 노드의 오른쪽 자식노드와 데이터를 교환하는 것입니다. 
		NodeAVL<T> * temp;
		temp = parent->r;
		parent->r = temp->l;
		temp->l = parent;
		return temp;
	} 

	// ll 회전 함수입니다.
	NodeAVL<T> * ll(NodeAVL<T> * parent)
	{
		// RR 회전과 반대입니다. 
		NodeAVL<T> * temp;
		temp = parent->l;
		parent->l = temp->r;
		temp->r = parent;
		return temp;
	} 

	// LR 회전 함수입니다. 
	NodeAVL<T> * lr(NodeAVL<T> * parent)
	{
		// LR 회전은 왼쪽 자식을 기준으로 RR, 본인을 기준으로 LL회전합니다. 
		NodeAVL<T> *  temp;
		temp = parent->l;
		parent->l = rr(temp);
		return ll(parent);
	}

	// RL 회전 함수입니다.
	NodeAVL<T> * rl(NodeAVL<T> * parent)
	{
		// LR 회전과 반대입니다.
		NodeAVL<T> *  temp;
		temp = parent->r;
		parent->r = ll(temp);
		return rr(parent); 
	}
	void _Delete(NodeAVL<T> * node) {
		if (node != NULL) {
			if (node->l != NULL) _Delete(node->l);
			if (node->r != NULL) _Delete(node->r);
			delete node;
		}
	}
};