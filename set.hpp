#ifndef SET_HPP
#define SET_HPP

#include <memory>
#include <iostream>
#include <functional>
#include "id.hpp"
#include "pair.hpp"
#include "equal.hpp"
#include "iterator.hpp"
#include "utilities.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template<typename Key, typename Node>
	class SetRBIterator
	{
		public:

			typedef size_t 						size_type;
			typedef ptrdiff_t 					difference_type;
			typedef bidirectional_iterator_tag 	iterator_category;
			typedef SetRBIterator<Key, Node>	Self;

			typedef Node* 	node_ptr;

			typedef Key*	pointer;
			typedef Key&	reference;
			typedef Key 	value_type;

		private:

			node_ptr _root;
			node_ptr _current;

		public:

			SetRBIterator()
			{
			}

			SetRBIterator(node_ptr x, node_ptr y) :
				_root(x),
				_current(y)
			{
			}

			SetRBIterator(const Self& x) :
				_root(x._root),
				_current(x._current)
			{
			}

			operator SetRBIterator<const Key, Node>() const
			{
				return (SetRBIterator<const Key, Node>(this->_root, this->_current));
			}

			~SetRBIterator()
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

	template<typename _Key, typename _Node>
	inline bool
	operator==(const SetRBIterator<_Key, _Node>& lhs,
				const SetRBIterator<_Key, _Node>& rhs)
	{
		return lhs._current == rhs._current;
	}

	template<typename _Key, typename _Node>
	inline bool
	operator!=(const SetRBIterator<_Key, _Node>& lhs,
				const SetRBIterator<_Key, _Node>& rhs)
	{
		return lhs._current != rhs._current;
	}

	template<typename Key, typename Compare>
	class SetRBTree
	{

		struct RBTreeNode
		{

			RBTreeNode(RBTreeNode* parent,
					   RBTreeNode* left,
					   RBTreeNode* right,
					   Key content,
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

			Key content;

			LEAFCOLOR color;
			NODEIDENTIFIER identifier;
		};

		public:

			typedef RBTreeNode node_type;
			typedef RBTreeNode *TNULL;
			typedef RBTreeNode *RBpointer;

			typedef Key value_type;
			typedef Key key_type;

			typedef SetRBIterator<const Key, node_type> iterator;
			typedef SetRBIterator<const Key, node_type> const_iterator;

			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef Compare compare;
			typedef SetRBTree<Key, Compare> Self;

		private:

			TNULL 								SENTINEL;
			RBpointer							_root;
			size_t 								_size;
			compare 							_cmp;
			std::allocator<node_type>			_node_allocator;
			typedef std::allocator<node_type> 	allocator_type;

		public:

			SetRBTree()
			{
				initializeSENTINEL();
				this->_root = SENTINEL;
				this->_size = 0;
			}

			SetRBTree(const compare& cmp, const allocator_type& alloc) :
				_cmp(cmp),
				_node_allocator(alloc)
			{
				initializeSENTINEL();
				this->_root = SENTINEL;
				this->_size = 0;
			}

			SetRBTree(const SetRBTree& x) :
				_node_allocator(x._node_allocator)
			{
				initializeSENTINEL();
				insert(x.begin(), x.end());
			}

			SetRBTree&
			operator=(const SetRBTree& x)
			{
				if (this != &x)
				{
					clear();
					const_iterator it = x.begin();
					while (it != x.end())
					{
						insert(*it, getRoot());
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

			~SetRBTree()
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
				while (x != SENTINEL && k != x->content)
				{
					if (k > x->content)
					{
						x = x->right;
					}
					else
					{
						x = x->left;
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
					if (_cmp(x->content, k))
					{
						x = x->right;
					}
					else if (_cmp(k, x->content))
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
			find(const key_type& k) const
			{
				return (iterator(this->_root, treeSearch(k)));
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

			void
			initializeSENTINEL()
			{
				SENTINEL = _node_allocator.allocate(1);
				_node_allocator.construct(SENTINEL, RBTreeNode(NULL, NULL, NULL, key_type(), BLACK, NULL_LEAF));
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
			insert(const key_type& content, RBpointer r)
			{
				RBpointer node = _node_allocator.allocate(1);
				_node_allocator.construct(node, RBTreeNode(NULL, SENTINEL, SENTINEL, content, RED, NODE));

				RBpointer y = NULL;
				RBpointer x = r;

				Compare cmp;
				bool rtvl;
				while (x != SENTINEL)
				{
					rtvl = cmp(node->content, x->content);
					y = x;
					if (x->content == node->content)
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
					rtvl = cmp(node->content, y->content);
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
			insert(iterator position, const key_type& content)
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
					insert(*first, this->_root);
					++first;
				}
			}

			iterator
			lower_bound(const key_type& k)
			{
				iterator it(this->_root, minimum(this->_root));
				while (it != end())
				{
					if (!_cmp(*it, k))
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
					if (!_cmp(*it, k))
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
					if (_cmp(k, *it))
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
					if (_cmp(k, *it))
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
				std::cout << x->content << std::endl;
				inOrder(x->right);
			}

			void
			printBT(const std::string &prefix, const RBpointer node, bool isLeft)
			{
				if (node != SENTINEL)
				{
					std::cout << prefix;
					std::cout << (isLeft ? "├──" : "└──");
					std::cout << node->content << std::endl;
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
			swap(Self &x)
			{
				ft::swap(this->_root, x._root);
				ft::swap(this->_size, x._size);
				ft::swap(this->SENTINEL, x.SENTINEL);
				ft::swap(this->_node_allocator, x._node_allocator);
				ft::swap(this->_cmp, x._cmp);
			}

			template<typename Key1, typename Compare1>
			friend inline bool operator==(const SetRBTree<Key1, Compare1> &lhs,
										const SetRBTree<Key1, Compare1> &rhs);
	};

	template <typename Key, typename Compare>
	inline bool
	operator==(const SetRBTree<Key, Compare>& lhs,
				const SetRBTree<Key, Compare>& rhs)
	{
		return lhs._size == rhs._size && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename Key, typename Compare>
	inline bool
	operator<(const SetRBTree<Key, Compare>& lhs,
				const SetRBTree<Key, Compare>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename Key, typename Compare>
	inline bool
	operator!=(const SetRBTree<Key, Compare>& lhs,
				const SetRBTree<Key, Compare>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename Key, typename Compare>
	inline bool
	operator>(const SetRBTree<Key, Compare>& lhs,
				const SetRBTree<Key, Compare>& rhs)
	{
		return rhs < lhs;
	}

	template <typename Key, typename Compare>
	inline bool
	operator<=(const SetRBTree<Key, Compare>& lhs,
				const SetRBTree<Key, Compare>& rhs)
	{
		return !(rhs < lhs);
	}

	template <typename Key, typename Compare>
	inline bool
	operator>=(const SetRBTree<Key, Compare>& lhs,
				const SetRBTree<Key, Compare>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename Key, typename Compare = std::less<Key>, typename Allocator = std::allocator<Key> >
	class set
	{

		public :

			class value_cmp
			{
				protected:

					Compare cmp;
					typedef Key value_type;

				public:

					value_cmp() :
						cmp(Compare())
					{
					}

					value_cmp(Compare c) :
						cmp(c)
					{
					}

					~value_cmp()
					{
					}

					bool
					operator()(const value_type& lhs, const value_type& rhs) const
					{
						return cmp(lhs, rhs);
					}
			};

		private :

			typedef SetRBTree<Key, Compare> _treeStruct;
			Compare		_cmp;
			_treeStruct _rbTree;

		public :

			typedef Key						key_type;

			typedef value_cmp				value_compare;
			typedef Compare					key_compare;
			typedef Allocator				allocator_type;

			typedef typename	Allocator::pointer			pointer;
			typedef typename	Allocator::const_pointer	const_pointer;
			typedef typename	Allocator::reference		reference;
			typedef typename	Allocator::const_reference	const_reference;

			typedef typename	_treeStruct::RBpointer				RBpointer;

			typedef typename	_treeStruct::iterator				iterator;
			typedef typename	_treeStruct::const_iterator			const_iterator;
			typedef typename 	_treeStruct::reverse_iterator		reverse_iterator;
			typedef typename	_treeStruct::const_reverse_iterator const_reverse_iterator;
			typedef typename	_treeStruct::size_type				size_type;
			typedef typename	_treeStruct::difference_type		difference_type;

			explicit set(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) :
				_rbTree(comp, alloc)
			{
			}

			template <typename InputIterator>
			set(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) :
				_rbTree(comp, alloc)
			{
				while (first != last)
				{
					_rbTree.insert(*first, _rbTree.getRoot());
					++first;
				}
			}

			set(const set& x) :
				_rbTree(x._rbTree)
			{
			}

			set&
			operator=(const set& x)
			{
				if (this != &x)
				{
					this->_rbTree = x._rbTree;
				}
				return *this;
			}

			iterator
			begin()
			{
				return _rbTree.begin();
			}

			const_iterator
			begin() const
			{
				return _rbTree.begin();
			}

			iterator
			end()
			{
				return _rbTree.end();
			}

			const_iterator
			end() const
			{
				return _rbTree.end();
			}

			reverse_iterator
			rbegin()
			{
				return _rbTree.rbegin();
			}

			const_reverse_iterator
			rbegin() const
			{
				return _rbTree.rbegin();
			}

			reverse_iterator
			rend()
			{
				return _rbTree.rend();
			}

			const_reverse_iterator
			rend() const
			{
				return _rbTree.rend();
			}

			bool
			empty() const
			{
				return _rbTree.size() == 0;
			}

			size_type
			size() const
			{
				return _rbTree.size();
			}

			size_type
			max_size() const
			{
				return _rbTree.max_size();
			}

			ft::pair<iterator, bool>
			insert(const key_type& k)
			{
				ft::pair<iterator, bool> tmp = _rbTree.insert(k, _rbTree.getRoot());
				return tmp;
			}

			iterator
			insert(iterator position, const key_type& k)
			{
				return _rbTree.insert(position, k);
			}

			template <typename InputIterator>
			void
			insert(InputIterator first, InputIterator last)
			{
				_rbTree.insert(first, last);
			}

			size_type
			erase(const key_type& k)
			{
				bool rtvl = _rbTree.deleteRBTreeNode(k);
				return rtvl == true ? 1 : 0;
			}

			void
			erase(iterator position)
			{
				_rbTree.deleteRBTreeNode(*position);
			}

			void
			erase(iterator first, iterator last)
			{
				while (first != last)
				{
					_rbTree.deleteRBTreeNode(*first++);
				}
			}

			void
			swap(set& x)
			{
				this->_rbTree.swap(x._rbTree);
			}

			void
			clear()
			{
				_rbTree.clear();
			}

			key_compare
			key_comp() const
			{
				return _cmp;
			}

			value_cmp
			value_comp() const
			{
				return value_cmp(_cmp);
			}

			void
			printBT()
			{
				_rbTree.printBT(_rbTree.getRoot());
			}

			iterator
			find(const key_type& k) const
			{
				return _rbTree.find(k);
			}

			size_type
			count(const key_type& k) const
			{
				return _rbTree.count(k);
			}

			iterator
			lower_bound(const key_type& k)
			{
				return _rbTree.lower_bound(k);
			}

			const_iterator
			lower_bound(const key_type& k) const
			{
				return _rbTree.lower_bound(k);
			}

			iterator
			upper_bound(const key_type& k)
			{
				return _rbTree.upper_bound(k);
			}

			const_iterator
			upper_bound(const key_type& k) const
			{
				return _rbTree.upper_bound(k);
			}

			ft::pair<const_iterator, const_iterator>
			equal_range(const key_type& k) const
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			ft::pair<iterator, iterator>
			equal_range(const key_type& k)
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			allocator_type
			get_allocator() const
			{
				return allocator_type(_rbTree.get_allocator());
			}

			template<typename Key1, typename Compare1, typename Allocator1>
			friend bool operator==(const ft::set<Key1, Compare1, Allocator1>& lhs,
				const ft::set<Key1, Compare1, Allocator1>& rhs);

			template<typename Key1, typename Compare1, typename Allocator1>
			friend bool operator<(const ft::set<Key1, Compare1, Allocator1>& lhs,
				const ft::set<Key1, Compare1, Allocator1>& rhs);

	};

	template<typename Key, typename Compare, typename Allocator>
	void swap(ft::set<Key, Compare, Allocator>& lhs, ft::set<Key, Compare, Allocator>& rhs)
	{
		lhs.swap(rhs);
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool
	operator==(const ft::set<Key, Compare, Alloc>& lhs,
				const ft::set<Key, Compare, Alloc>& rhs)
	{
		return lhs._rbTree == rhs._rbTree;
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool
	operator<(const ft::set<Key, Compare, Alloc>& lhs,
				const ft::set<Key, Compare, Alloc>& rhs)
	{
		return lhs._rbTree < rhs._rbTree;
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool
	operator!=(const ft::set<Key, Compare, Alloc>& lhs,
				const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool
	operator>(const ft::set<Key, Compare, Alloc>& lhs,
				const ft::set<Key, Compare, Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool
	operator<=(const ft::set<Key, Compare, Alloc>& lhs,
				const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename Key, typename Compare, typename Alloc>
	inline bool
	operator>=(const ft::set<Key, Compare, Alloc>& lhs,
				const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
};
#endif