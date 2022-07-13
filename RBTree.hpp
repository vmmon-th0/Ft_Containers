#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <memory>
#include "id.hpp"
#include "pair.hpp"
#include "equal.hpp"
#include "types.hpp"
#include "rainbow.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"

template <typename Tp, typename Val, typename Key, typename Compare>
class RBTree;

namespace ft
{
	template <typename Tp, typename PairTp>
	class RBIterator
	{
		public:

			typedef size_t 						size_type;
			typedef ptrdiff_t 					difference_type;
			typedef bidirectional_iterator_tag 	iterator_category;
			typedef RBIterator<Tp, PairTp>		Self;

			typedef Tp*		node_ptr;

			typedef PairTp*	pointer;
			typedef PairTp&	reference;
			typedef PairTp 	value_type;

		private:

			node_ptr _root;
			node_ptr _current;

		public:

			RBIterator()
			{
			}

			RBIterator(node_ptr x, node_ptr y) :
				_root(x),
				_current(y)
			{
			}

			RBIterator(const Self& x) :
				_root(x._root),
				_current(x._current)
			{
			}

			operator RBIterator<Tp, const PairTp>() const
			{
				return (RBIterator<Tp, const PairTp>(this->_root, this->_current));
			}

			~RBIterator()
			{
			}

			Self&
			operator=(const Self& x)
			{
				if (this != &x)
				{
					this->_root = x._root;
					this->_current = x._current;
				}
				return *this;
			}

			Self&
			operator++()
			{
				node_ptr x = this->_current;
				if (x->right->identifier != NULL_LEAF)
				{
					x = x->right;
					while (x->left->identifier != NULL_LEAF && x->identifier != NULL_LEAF)
					{
						x = x->left;
					}
					this->_current = x;
				}
				else
				{
					node_ptr y = x->parent;
					while (y != NULL && y->identifier != NULL_LEAF && x == y->right)
					{
						x = y;
						y = y->parent;
					}
					if (y == NULL)
					{
						y = this->_current->right;
					}
					this->_current = y;
				}
				return *this;
			}

			Self
			operator++(int)
			{
				Self tmp = *this;
				operator++();
				return tmp;
			}

			Self&
			operator--()
			{
				node_ptr x = this->_current;
				if (x->identifier == NULL_LEAF)
				{
					x = this->_root;
					while (x->right->identifier != NULL_LEAF)
					{
						x = x->right;
					}
					this->_current = x;
					return *this;
				}
				if (x->left->identifier != NULL_LEAF)
				{
					x = x->left;
					while (x->left->identifier != NULL_LEAF && x->identifier != NULL_LEAF)
					{
						x = x->right;
					}
					if (x->left->identifier == NULL_LEAF && x->right->identifier != NULL_LEAF)
					{
						x = x->right;
					}
					this->_current = x;
				}
				else
				{
					node_ptr y = x->parent;
					while (y != NULL && y->identifier != NULL_LEAF && x == y->left)
					{
						x = y;
						y = y->parent;
					}
					if (y == NULL)
					{
						y = this->_current->right;
					}
					this->_current = y;
				}
				return *this;
			}

			Self
			operator--(int)
			{
				Self tmp = *this;
				operator--();
				return tmp;
			}

			pointer
			operator->() const
			{
				return &_current->content;
			}

			reference
			operator*() const
			{
				return _current->content;
			}

			bool
			operator==(const Self& x) const
			{
				return this->_current == x._current;
			}

			bool
			operator!=(const Self& x) const
			{
				return this->_current != x._current;
			}

			const node_ptr&
			base() const
			{
				return this->_current;
			}
	};

	template <typename _Tp, typename _PairTp>
	inline bool
	operator==(const RBIterator<_Tp, _PairTp> &lhs,
				const RBIterator<_Tp, _PairTp> &rhs)
	{
		return lhs._current == rhs._current;
	}

	template <typename _Tp, typename _PairTp>
	inline bool
	operator!=(const RBIterator<_Tp, _PairTp> &lhs,
				const RBIterator<_Tp, _PairTp> &rhs)
	{
		return lhs._current != rhs._current;
	}

	template <typename Tp, typename Val, typename Key, typename Compare>
	class RBTree
	{

		struct RBTreeNode
		{

			RBTreeNode(RBTreeNode* parent,
					   RBTreeNode* left,
					   RBTreeNode* right,
					   Tp content,
					   LEAFCOLOR color,
					   NODEIDENTIFIER id) :
				parent(parent),
				left(left),
				right(right),
				content(content),
				color(color),
				identifier(id)
			{
			}

			~RBTreeNode()
			{
			}

			RBTreeNode *parent;
			RBTreeNode *left;
			RBTreeNode *right;

			Tp content;

			LEAFCOLOR color;
			NODEIDENTIFIER identifier;
		};

		public:

			typedef RBTreeNode node_type;
			typedef RBTreeNode *TNULL;
			typedef RBTreeNode *RBpointer;

			typedef Tp value_type;
			typedef Key key_type;

			typedef RBIterator<node_type, value_type>		iterator;
			typedef RBIterator<node_type, const value_type>	const_iterator;

			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			typedef size_t							size_type;
			typedef ptrdiff_t						difference_type;
			typedef Compare							compare;
			typedef RBTree<Tp, Val, Key, Compare>	Self;

		private:

			TNULL 								SENTINEL;
			RBpointer							_root;
			size_t 								_size;
			compare 							_cmp;
			std::allocator<node_type>			_node_allocator;
			typedef std::allocator<node_type> 	allocator_type;
			typedef typename std::allocator<node_type>::template rebind<node_type>::other other_allocator_type;

		public:

			RBTree()
			{
				initializeSENTINEL();
				this->_root = SENTINEL;
				this->_size = 0;
			}

			RBTree(const compare& cmp, const allocator_type& alloc) :
				_cmp(cmp),
				_node_allocator(alloc)
			{
				initializeSENTINEL();
				this->_root = SENTINEL;
				this->_size = 0;
			}

			RBTree(const RBTree& x) :
				_node_allocator(x._node_allocator)
			{
				initializeSENTINEL();
				insert(x.begin(), x.end());
			}

			RBTree&
			operator=(const RBTree& x)
			{
				if (this != &x)
				{
					clear();
					const_iterator it = x.begin();
					while (it != x.end())
					{
						insert(ft::make_pair(it->first, it->second), getRoot());
						++it;
					}
				}
				return *this;
			}

			void
			removeAll(RBpointer x)
			{
				if (x == SENTINEL || x == NULL)
				{
					return;
				}
				removeAll(x->left);
				removeAll(x->right);
				_node_allocator.destroy(x);
				_node_allocator.deallocate(x, 1);
				x = NULL;
			}

			void
			clear()
			{
				removeAll(this->_root);
				this->_size = 0;
				this->_root = SENTINEL;
			}

			~RBTree()
			{
				removeAll(this->_root);
				_node_allocator.destroy(SENTINEL);
				_node_allocator.deallocate(SENTINEL, 1);
			}

			RBpointer
			maximum(RBpointer node) const
			{
				if (node == SENTINEL)
				{
					return node;
				}
				while (node->right != SENTINEL)
				{
					node = node->right;
				}
				return node;
			}

			RBpointer
			minimum(RBpointer node) const
			{
				if (node == SENTINEL)
				{
					return node;
				}
				while (node->left != SENTINEL)
				{
					node = node->left;
				}
				return node;
			}

			/* Is BST Iterative search more optimized than recursive ? Indeed in the most of cases iterative search are faster and require less space.
				BST Recusrive launch 1 stack call for every move in the BST, that can become slow in large amounts of data, but,
				sometimes the compiler can optimize it with  [ https://en.wikipedia.org/wiki/Tail_call ]. */

			RBpointer
			treeSearch(const key_type& k) const
			{
				RBpointer x = this->_root;
				while (x != SENTINEL)
				{
					if (_cmp(x->content.first, k))
					{
						x = x->right;
					}
					else if (_cmp(k, x->content.first))
					{
						x = x->left;
					}
					else
					{
						break ;
					}
				}
				return x;
			}

			size_type
			count (const key_type& k) const
			{
				RBpointer x = this->_root;
				while (x != SENTINEL)
				{
					if (_cmp(x->content.first, k))
					{
						x = x->right;
					}
					else if (_cmp(k, x->content.first))
					{
						x = x->left;
					}
					else
					{
						break ;
					}
				}
				return x != SENTINEL;
			}

			iterator
			find(const key_type& k)
			{
				return (iterator(this->_root, treeSearch(k)));
			}

			const_iterator
			find(const key_type& k) const
			{
				return (const_iterator(this->_root, treeSearch(k)));
			}

			iterator
			begin()
			{
				return iterator(this->_root, minimum(this->_root));
			}

			const_iterator
			begin() const
			{
				return const_iterator(this->_root, minimum(this->_root));
			}

			iterator
			end()
			{
				return iterator(this->_root, SENTINEL);
			}

			const_iterator
			end() const
			{
				return const_iterator(this->_root, SENTINEL);
			}

			reverse_iterator
			rbegin()
			{
				return reverse_iterator(iterator(this->_root, SENTINEL));
			}

			const_reverse_iterator
			rbegin() const
			{
				return const_reverse_iterator(maximum(this->_root));
			}

			reverse_iterator
			rend()
			{
				return reverse_iterator(iterator(this->_root, minimum(this->_root)));
			}

			const_reverse_iterator
			rend() const
			{
				return const_reverse_iterator(minimum(this->_root));
			}

			/*  In computer programming, a sentinel node is a specifically designated node used with linked lists
			and trees as a traversal path terminator. This type of node does not hold or reference any data managed by the data structure. 
			In RBTREE we can use sentinels in severals ways, Either we assign a sentinel to each leaf of the tree, or we point all the leaves towards the same sentinel, the second solution wins in terms of space complexity */

			void
			initializeSENTINEL()
			{
				SENTINEL = _node_allocator.allocate(1);
				_node_allocator.construct(SENTINEL, RBTreeNode(NULL, NULL, NULL, value_type(), BLACK, NULL_LEAF));
				this->_root = SENTINEL;
				this->_size = 0;
			}

			size_type
			size() const
			{
				return this->_size;
			}

			size_type
			max_size() const
			{
				return _node_allocator.max_size();
			}

			void
			incrementSize()
			{
				++this->_size;
			}

			void
			decrementSize()
			{
				--this->_size;
			}

			void
			rbTransplant(RBpointer u, RBpointer v)
			{
				if (u->parent == NULL)
				{
					this->_root = v;
				}
				else if (u == u->parent->left)
				{
					u->parent->left = v;
				}
				else
				{
					u->parent->right = v;
				}
				v->parent = u->parent;
			}

			/*
				Deletion ALG in RB Trees :

					- Case 1 : If node to be deleted is red, just delete it.

					- Case 2 : If root is DB, just remove DB.

					- Case 3 : If DB's sibling is black & both its children are black
						-> Remove DB
						-> Add black to its parent.
							-> If parent is red it becomes black.
							-> If parent is black it becomes double black.
						-> Make sibling red.
						-> if still DB exists, apply other cases.

					- Case 4 : if DB's sibling is red.
						-> swap colors of parent & it's sibling.
						-> rotate parent in DB direction.

					- Case 5 : DB's sibling is black, sibling's child who is far from DB is black, but near child to DB is red.
						-> swap color of DB's sibling & siblings child who is near to DB.
						-> rotate sibling in opposite direction to DB.
						-> apply case 6.

					- Case 6 : DB's sibling is black, far child is red
						-> swap color of parent & sibling.
						-> rotate parent in DB's direction.
						-> remove DB.
						-> change color of red child to black.
			*/

			void
			RbDeleteFixUp(RBpointer x)
			{
				RBpointer s;
				while (x != this->_root && x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							leftRotate(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								rightRotate(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							leftRotate(x->parent);
							x = this->_root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							rightRotate(x->parent);
							s = x->parent->left;
						}
						if (s->right->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								leftRotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							rightRotate(x->parent);
							x = this->_root;
						}
					}
				}
				x->color = BLACK;
			}

			bool
			deleteRBTreeNode(const key_type k)
			{
				RBpointer z = treeSearch(k);
				RBpointer x, y;
				if (z == SENTINEL)
				{
					return false;
				}
				else
				{
					decrementSize();
				}
				y = z;
				int y_original_color = y->color;
				if (z->left == SENTINEL)
				{
					x = z->right;
					rbTransplant(z, z->right);
				}
				else if (z->right == SENTINEL)
				{
					x = z->left;
					rbTransplant(z, z->left);
				}
				else
				{
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z)
					{
						x->parent = y;
					}
					else
					{
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				_node_allocator.destroy(z);
				_node_allocator.deallocate(z, 1);
				if (y_original_color == BLACK)
				{
					RbDeleteFixUp(x);
				}
				return true;
			}

			RBpointer
			successor(RBpointer x)
			{
				if (x->right != SENTINEL)
				{
					return minimum(x->right);
				}
				RBpointer y = x->parent;
				while (y != SENTINEL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			RBpointer
			predecessor(RBpointer x)
			{
				if (x->left != SENTINEL)
				{
					return maximum(x->left);
				}
				RBpointer y = x->parent;
				while (y != SENTINEL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			/* In discrete mathematics, tree rotation is an operation on a binary tree that changes the structure without interfering with the order
			of the elements. A tree rotation moves one node up in the tree and one node down.
			It is used to change the shape of the tree, and in particular to decrease its height by moving smaller subtrees down and larger subtrees up,
			resulting in improved performance of many tree operations. */

			void
			leftRotate(RBpointer x)
			{
				RBpointer y = x->right;
				x->right = y->left;
				if (y->left != SENTINEL)
				{
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL)
				{
					this->_root = y;
				}
				else if (x == x->parent->left)
				{
					x->parent->left = y;
				}
				else
				{
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}

			void
			rightRotate(RBpointer x)
			{
				RBpointer y = x->left;
				x->left = y->right;
				if (y->right != SENTINEL)
				{
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL)
				{
					this->_root = y;
				}
				else if (x == x->parent->right)
				{
					x->parent->right = y;
				}
				else
				{
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}

			void
			RbInsertFixUp(RBpointer k)
			{
				RBpointer u;
				while (k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							leftRotate(k->parent->parent);
						}
					}
					else
					{
						u = k->parent->parent->right;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							rightRotate(k->parent->parent);
						}
					}
					if (k == this->_root)
					{
						break;
					}
				}
				this->_root->color = BLACK;
			}

			ft::pair<iterator, bool>
			insert(const value_type& content, RBpointer r)
			{
				RBpointer node = _node_allocator.allocate(1);
				_node_allocator.construct(node, RBTreeNode(NULL, SENTINEL, SENTINEL, content, RED, NODE));

				RBpointer y = NULL;
				RBpointer x = r;
				bool rtvl;
				while (x != SENTINEL)
				{
					rtvl = _cmp(node->content.first, x->content.first);
					y = x;
					if (!rtvl && !_cmp(x->content.first, node->content.first))
					{
						_node_allocator.destroy(node);
						_node_allocator.deallocate(node, 1);
						return ft::make_pair(iterator(this->_root, x), false);
					}
					if (rtvl == true)
					{
						x = x->left;
					}
					else
					{
						x = x->right;
					}
				}
				node->parent = y;
				if (y == NULL)
				{
					this->_root = node;
				}
				else
				{
					rtvl = _cmp(node->content.first, y->content.first);
					if (rtvl == true)
					{
						y->left = node;
					}
					else
					{
						y->right = node;
					}
				}
				incrementSize();
				if (node->parent == NULL)
				{
					node->color = BLACK;
					return ft::make_pair(iterator(this->_root, node), true);
				}
				if (node->parent->parent == NULL)
				{
					return ft::make_pair(iterator(this->_root, node), true);
				}
				RbInsertFixUp(node);
				return ft::make_pair(iterator(this->_root, node), true);
			}

			iterator
			insert(iterator position, const value_type& content)
			{
				(void)position;
				ft::pair<iterator, bool> p = insert(content, this->_root);
				return p.first;
			}

			template<typename InputIterator>
			void
			insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(ft::make_pair(first->first, first->second), this->_root);
					++first;
				}
			}

			iterator
			lower_bound(const key_type& k)
			{
				iterator it(this->_root, minimum(this->_root));
				while (it != end())
				{
					if (!_cmp(it->first, k))
					{
						return it;
					}
					++it;
				}
				return end();
			}

			const_iterator
			lower_bound(const key_type& k) const
			{
				const_iterator it(this->_root, minimum(this->_root));
				while (it != end())
				{
					if (!_cmp(it->first, k))
					{
						return it;
					}
					++it;
				}
				return end();
			}

			iterator
			upper_bound(const key_type& k)
			{
				iterator it(this->_root, minimum(this->_root));
				while (it != end())
				{
					if (_cmp(k, it->first))
					{
						return it;
					}
					++it;
				}
				return end();
			}

			const_iterator
			upper_bound(const key_type& k) const
			{
				const_iterator it(this->_root, minimum(this->_root));
				while (it != end())
				{
					if (_cmp(k, it->first))
					{
						return it;
					}
					++it;
				}
				return end();
			}

			RBpointer
			getRoot() const
			{
				return this->_root;
			}

			void
			inOrder(RBpointer x)
			{
				if (x == SENTINEL)
				{
					return;
				}
				inOrder(x->left);
				std::cout << x->content.first << std::endl;
				inOrder(x->right);
			}

			void
			printBT(const std::string& prefix, const RBpointer node, bool isLeft)
			{
				if (node != SENTINEL)
				{
					std::cout << prefix;
					std::cout << (isLeft ? "├──" : "└──");

					if (node->color == BLACK)
					{
						std::cout << BLACK2 << node->content.first << RESET << std::endl;
					}
					else if (node->color == RED)
					{
						std::cout << RED2 << node->content.first << RESET << std::endl;
					}
					printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
					printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
				}
			}

			void
			printBT(const RBpointer node)
			{
				printBT("", node, false);
			}

			void
			swap(Self& x)
			{
				ft::swap(this->_root, x._root);
				ft::swap(this->_size, x._size);
				ft::swap(this->SENTINEL, x.SENTINEL);
				ft::swap(this->_node_allocator, x._node_allocator);
				ft::swap(this->_cmp, x._cmp);
			}

			template <typename Tp1, typename Val1, typename Key1, typename Compare1>
			friend inline bool operator==(const RBTree<Tp1, Val1, Key1, Compare1>& lhs,
											const RBTree<Tp1, Val1, Key1, Compare1>& rhs);
	};

	template <typename Tp, typename Val, typename Key, typename Compare>
	inline bool
	operator==(const RBTree<Tp, Val, Key, Compare>& lhs,
				const RBTree<Tp, Val, Key, Compare>& rhs)
	{
		return lhs._size == rhs._size && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename Tp, typename Val, typename Key, typename Compare>
	inline bool
	operator<(const RBTree<Tp, Val, Key, Compare>& lhs,
				const RBTree<Tp, Val, Key, Compare>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename Tp, typename Val, typename Key, typename Compare>
	inline bool
	operator!=(const RBTree<Tp, Val, Key, Compare>& lhs,
				const RBTree<Tp, Val, Key, Compare>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename Tp, typename Val, typename Key, typename Compare>
	inline bool
	operator>(const RBTree<Tp, Val, Key, Compare>& lhs,
				const RBTree<Tp, Val, Key, Compare>& rhs)
	{
		return rhs < lhs;
	}

	template <typename Tp, typename Val, typename Key, typename Compare>
	inline bool
	operator<=(const RBTree<Tp, Val, Key, Compare>& lhs,
				const RBTree<Tp, Val, Key, Compare>& rhs)
	{
		return !(rhs < lhs);
	}

	template <typename Tp, typename Val, typename Key, typename Compare>
	inline bool
	operator>=(const RBTree<Tp, Val, Key, Compare>& lhs,
				const RBTree<Tp, Val, Key, Compare>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif