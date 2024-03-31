// xtree internal header

#ifndef XTREE
#define XTREE

enum class Color { Red, Black }; // colors for link to parent

template< typename Ty >
struct TreeNode
{
	using NodePtr = TreeNode*;
	using value_type = Ty;

	NodePtr    left;   // left subtree, or smallest element if head
	NodePtr    parent; // parent, or root of tree if head
	NodePtr    right;  // right subtree, or largest element if head
	Color      color;  // Red or Black, Black if head
	bool       isNil;  // true only if head (also nil) node
	value_type myval;  // the stored value, unused if head
};

// CLASS TEMPLATE TreeVal
template< typename Ty >
class TreeVal
{
public:
	using NodePtr = TreeNode< Ty >*;

	using value_type = Ty;
	using size_type = size_t;

	TreeVal()
		: myHead(new TreeNode< value_type >),
		mySize(0)
	{
		myHead->left = myHead;
		myHead->parent = myHead;
		myHead->right = myHead;
		myHead->color = Color::Black;
		myHead->isNil = true;
	}

	~TreeVal()
	{
		clear(myHead->parent);
		delete myHead;
	}

	// Removes all elements from the set object (which are destroyed)
	void clear(TreeNode< value_type >* node)
	{
		if (!node->isNil) // node is not an external node
		{
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	// rebalance for insertion
	void reBalance(TreeNode< value_type >* node)
	{  // node->parent cannot be the root
		TreeNode<value_type>* root = myHead->parent, * pu = node->parent;
		while (node->color == pu->color) {
			TreeNode<value_type>* gu = pu->parent;
			if (pu == gu->left) {
				if (gu->right->color == Color::Red) {
					pu->color = Color::Black;
					gu->right->color = Color::Black;
				}
				else {//gu->right->color == Color::Black
					if (node == pu->left) {
						LLRotation(pu);
						pu->color = Color::Black;
					}
					else {//node == pu->right
						LRRotation(node);
						LLRotation(node);
						node->color = Color::Black;
					}
				}
				gu->color = Color::Red;
			}
			else {//pu == gu->right
				if (gu->left->color == Color::Red) {
					pu->color = Color::Black;
					gu->left->color = Color::Black;
				}
				else {//gu->left->color == Color::Black
					if (node == pu->right) {
						RRRotation(pu);
						pu->color = Color::Black;
					}
					else {//node == pu->left
						RLRotation(node);
						RRRotation(node);
						node->color = Color::Black;
					}
				}
				gu->color = Color::Red;
			}
			node = gu;
			pu = node->parent;
			gu = pu->parent;
		}
		myHead->parent->color = Color::Black;
	}

	// rotate right at g, where p = g->left and node = p->left
	//void set< Kty >::LLbRotation( TreeNode< value_type > *node )
	void LLRotation(TreeNode< value_type >* p)
	{
		TreeNode<value_type>* gp = p->parent, * gpp = gp->parent, * node = p->right;
		if (node != myHead)
			node->parent = gp;
		p->parent = gp->parent;
		gp->left = p->right;
		p->right = gp;
		gp->parent = p;
		if (myHead == gpp)
			gpp->parent = p;
		else if (gp == gpp->right)
			gpp->right = p;
		else
			gpp->left = p;
	}

	// LR rotation; p = g->left and node = p->right
	void LRRotation(TreeNode< value_type >* node)
	{
		TreeNode<value_type>* p = node->parent, * gp = p->parent;
		if (node->left != myHead)
			node->left->parent = p;
		p->right = node->left;
		p->parent = node;
		gp->left = node;
		node->parent = gp;
		node->left = p;
	}

	// RL rotation; p = g->right and node = p->left
	void RLRotation(TreeNode< value_type >* node)
	{
		TreeNode<value_type>* p = node->parent, * gp = p->parent;
		if (node->right != myHead)
			node->right->parent = p;
		p->left = node->right;
		p->parent = node;
		gp->right = node;
		node->parent = gp;
		node->right = p;
	}

	// rotate left at g, where p = g->right and node = p->right
	//void set< Kty >::RRbRotation( TreeNode< value_type > *node )
	void RRRotation(TreeNode< value_type >* p)
	{
		TreeNode<value_type>* gp = p->parent, * gpp = gp->parent, * node = p->left;
		if (node != myHead)
			node->parent = gp;
		p->parent = gp->parent;
		gp->right = p->left;
		p->left = gp;
		gp->parent = p;
		if (myHead == gpp)
			gpp->parent = p;
		else if (gp == gpp->right)
			gpp->right = p;
		else
			gpp->left = p;
	}

	// erase node provided that the degree of node is at most one
	void eraseDegreeOne(TreeNode< value_type >* node)
	{
		TreeNode<value_type>* root = myHead->parent, * child = myHead;
		if (node == root) {
			delete node;
			myHead->parent = myHead;
			mySize--;
			return;
		}
		if (node->left != myHead) {
			child = node->left;
			child->parent = node->parent;
			if (node->parent->left == node)
				node->parent->left = child;
			else//node->parent->right == node
				node->parent->right = child;
		}
		else if (node->right != myHead) {
			child = node->right;
			child->parent = node->parent;
			if (node->parent->left == node)
				node->parent->left = child;
			else//node->parent->right == node
				node->parent->right = child;
		}
		else {
			if (node == node->parent->right)
				node->parent->right = myHead;
			else
				node->parent->left = myHead;
		}

		if (node->color == Color::Black)
			fixUp(child, node->parent);

		delete node;
		mySize--;
	}

	// rebalance for deletion
	void fixUp(TreeNode< value_type >* N, TreeNode< value_type >* P)
	{
		if (N->color == Color::Red) {
			N->color = Color::Black;
			return;
		}
		if (N == P->left) {
			TreeNode<value_type>* S = P->right, * SL = S->left, * SR = S->right;
			if (S->color == Color::Black && SR->color == Color::Black && SL->color == Color::Black && P->color == Color::Red) {//Case4
				P->color = Color::Black;
				S->color = Color::Red;
				return;
			}
			else if (S->color == Color::Black && SR->color == Color::Red) {//Case2
				RRRotation(S);
				S->color = P->color;
				P->color = SR->color = Color::Black;
				return;
			}
			else if (S->color == Color::Black && SR->color == Color::Black && SL->color == Color::Red) {//Case3
				RLRotation(SL);
				SL->color = Color::Black;
				S->color = Color::Red;
				fixUp(N, P);
				return;
			}
			else if (S->color == Color::Red) {//Case1
				RRRotation(S);
				P->color = Color::Red;
				S->color = Color::Black;
				fixUp(N, P);
				return;
			}
			else if (S->color == Color::Black && SR->color == Color::Black && SL->color == Color::Black && P->color == Color::Black) {//Case5
				S->color = Color::Red;
				fixUp(P, P->parent);
				return;
			}
		}
		else {//N == P->right
			TreeNode<value_type>* S = P->left, * SL = S->left, * SR = S->right;
			if (S->color == Color::Black && SL->color == Color::Black && SR->color == Color::Black && P->color == Color::Red) {//Case4
				P->color = Color::Black;
				S->color = Color::Red;
				return;
			}
			else if (S->color == Color::Black && SL->color == Color::Red) {//Case2
				LLRotation(S);
				S->color = P->color;
				P->color = SL->color = Color::Black;
				return;
			}
			else if (S->color == Color::Black && SL->color == Color::Black && SR->color == Color::Red) {//Case3
				LRRotation(SR);
				SR->color = Color::Black;
				S->color = Color::Red;
				fixUp(N, P);
				return;
			}
			else if (S->color == Color::Red) {//Case1
				LLRotation(S);
				P->color = Color::Red;
				S->color = Color::Black;
				fixUp(N, P);
				return;
			}
			else if (S->color == Color::Black && SR->color == Color::Black && SL->color == Color::Black && P->color == Color::Black) {//Case5
				S->color = Color::Red;
				fixUp(P, P->parent);
				return;
			}
		}
	}

	// preorder traversal and inorder traversal
	void twoTraversals()
	{
		cout << "Preorder sequence:\n";
		preorder(myHead->parent);

		cout << "\nInorder sequence:\n";
		inorder(myHead->parent);
		cout << endl;
	}

	// preorder traversal
	void preorder(TreeNode< value_type >* node)
	{
		if (node != myHead)
		{
			cout << setw(5) << node->myval << (node->color == Color::Red ? "R" : "B");
			preorder(node->left);
			preorder(node->right);
		}
	}

	// inorder traversal
	void inorder(TreeNode< value_type >* node)
	{
		if (node != myHead)
		{
			inorder(node->left);
			cout << setw(5) << node->myval << (node->color == Color::Red ? "R" : "B");
			inorder(node->right);
		}
	}

	NodePtr myHead;   // pointer to head node
	size_type mySize; // number of elements
};

// CLASS TEMPLATE Tree
template< typename Traits >
class Tree // ordered red-black tree for map/multimap/set/multiset
{
public:
	using value_type = typename Traits::value_type;

protected:
	using ScaryVal = TreeVal< value_type >;

public:
	using key_type = typename Traits::key_type;
	using key_compare = typename Traits::key_compare;

	using size_type = size_t;

	Tree(const key_compare& parg)
		: keyCompare(parg),
		scaryVal()
	{
	}

	~Tree()
	{
	}

	// Extends the container by inserting a new element,
	// effectively increasing the container size by one.
	void insert(const value_type& val)
	{
		TreeNode<value_type>* root = scaryVal.myHead->parent, * p = root, * pp = root->parent;
		while (p != root->parent) {
			pp = p;
			if (keyCompare(p->myval, val))
				p = p->right;
			else if (keyCompare(val, p->myval))
				p = p->left;
			else
				return;
		}
		p = new TreeNode<value_type>();
		p->myval = val;
		p->isNil = false;
		p->color = Color::Black;
		p->left = p->right = p->parent = scaryVal.myHead;
		scaryVal.mySize++;
		if (root != scaryVal.myHead)
			if (keyCompare(val, pp->myval)) {
				pp->left = p;
				p->parent = pp;
			}
			else {
				pp->right = p;
				p->parent = pp;
			}
		else {
			scaryVal.myHead->parent = p;
			return;
		}
		p->color = Color::Red;
		scaryVal.reBalance(p);
	}

	// Removes from the set container a single element whose value is val
	// This effectively reduces the container size by one, which are destroyed.
	// Returns the number of elements erased.
	size_type erase(const key_type& val)
	{
		TreeNode<value_type>* root = scaryVal.myHead->parent, * p = root, * pp = root->parent;
		while (p != root->parent && p->myval != val) {
			pp = p;
			if (keyCompare(val, p->myval))
				p = p->left;
			else
				p = p->right;
		}
		if (p != root->parent) {
			if (p->right == root->parent || p->left == root->parent)
				scaryVal.eraseDegreeOne(p);
			else {
				TreeNode<value_type>* parent = p, * rightSubtreeMin = p->right;
				while (rightSubtreeMin->left != root->parent) {
					parent = rightSubtreeMin;
					rightSubtreeMin = rightSubtreeMin->left;
				}
				p->myval = rightSubtreeMin->myval;
				scaryVal.eraseDegreeOne(rightSubtreeMin);
			}
			return 1;
		}
		return 0;
	}

private:
	key_compare keyCompare;
	ScaryVal scaryVal;
};

#endif // XTREE