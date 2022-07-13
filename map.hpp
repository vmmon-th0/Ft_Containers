#ifndef MAP_HPP
#define MAP_HPP

#include "vector.hpp"
#include <iostream>
#include <functional>
#include "pair.hpp"
#include "RBTree.hpp"
#include "utilities.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template<typename Key, typename Tp, typename Compare = std::less<Key>, typename Allocator = std::allocator< ft::pair<const Key, Tp> > >
	class map
	{
		public :

			/* The comparison object returned is an object of the member type map::value_compare,
			which is a nested class that uses the internal comparison object to generate the appropriate comparison functional class. */

			class value_cmp
			{
				protected:
					Compare cmp;
					typedef typename ft::pair<Key, Tp> value_type;

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
						return cmp(lhs.first, rhs.first);
					}
			};

		private :

			typedef RBTree<ft::pair<Key, Tp>, Tp, Key, Compare> _treeStruct;
			Compare		_cmp;
			_treeStruct _rbTree;

		public :

			typedef Key						key_type;
			typedef Tp						mapped_type;
			typedef ft::pair<Key, Tp>		value_type;
			typedef Compare					key_compare;
			typedef value_cmp				value_compare;
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

			explicit map(const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()) :
				_rbTree(comp, alloc)
			{
			}

			template<typename InputIterator>
			map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_rbTree(comp, alloc)
			{
				while (first != last)
				{
					value_type tmp = ft::make_pair(first->first, first->second);
					_rbTree.insert(tmp, _rbTree.getRoot());
					++first;
				}
			}

			map(const map& x) :
				_rbTree(x._rbTree)
			{
			}

			~map()
			{
			}

			allocator_type
			get_allocator() const
			{
				return allocator_type(_rbTree.get_allocator());
			}

			map&
			operator=(const map& x)
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

			iterator
			find(const key_type& k)
			{
				return _rbTree.find(k);
			}

			const_iterator
			find(const key_type& k) const
			{
				return _rbTree.find(k);
			}

			mapped_type&
			operator[](const key_type& k)
			{
				return insert(ft::make_pair(k, mapped_type())).first->second;
			}

			ft::pair<iterator, bool>
			insert(const value_type& value)
			{
				ft::pair<iterator, bool> tmp = _rbTree.insert(value, _rbTree.getRoot());
				return tmp;
			}

			iterator
			insert(iterator position, const value_type& val)
			{
				return _rbTree.insert(position, val);
			}

			template<typename InputIterator>
  			void
			insert(InputIterator first, InputIterator last)
			{
				_rbTree.insert(first, last);
			}

			bool
			empty() const
			{
				return _rbTree.size() == 0;	
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
				_rbTree.deleteRBTreeNode(position->first);
			}

			void
			erase(iterator first, iterator last)
			{
				while (first != last)
				{
					_rbTree.deleteRBTreeNode(first++->first);
				}
			}

			void
			clear()
			{
				_rbTree.clear();
			}

			size_type
			count(const key_type& k) const
			{
				return _rbTree.count(k);
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

			/* https://en.wikipedia.org/wiki/Upper_and_lower_bounds */

			iterator
			lower_bound(const key_type& k)
			{
				return this->_rbTree.lower_bound(k);
			}

			const_iterator
			lower_bound(const key_type& k) const
			{
				return this->_rbTree.lower_bound(k);
			}

			iterator
			upper_bound(const key_type& k)
			{
				return this->_rbTree.upper_bound(k);
			}

			const_iterator
			upper_bound(const key_type& k) const
			{
				return this->_rbTree.upper_bound(k);
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

			// void
			// inOrder()
			// {
			// 	_rbTree.inOrder(_rbTree.getRoot());
			// }

			// void
			// printBT()
			// {
			// 	_rbTree.printBT(_rbTree.getRoot());
			// }

			void swap(map& x)
			{
				this->_rbTree.swap(x._rbTree);
			}

			template<typename Key1, typename Tp1, typename Compare1, typename Alloc1>
			friend bool operator==(const ft::map<Key1, Tp1, Compare1, Alloc1>& lhs,
				const ft::map<Key1, Tp1, Compare1, Alloc1>& rhs);

			template<typename Key1, typename Tp1, typename Compare1, typename Alloc1>
			friend bool operator<(const ft::map<Key1, Tp1, Compare1, Alloc1>& lhs,
				const ft::map<Key1, Tp1, Compare1, Alloc1>& rhs);

	};

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	void
	swap(ft::map<Key,Tp,Compare,Alloc>& lhs,
			ft::map<Key,Tp,Compare,Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool
	operator==(const ft::map<Key, Tp, Compare, Alloc>& lhs,
				const ft::map<Key, Tp, Compare, Alloc>& rhs)
	{
		return lhs._rbTree == rhs._rbTree;
	}
	
	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool
	operator<(const ft::map<Key, Tp, Compare, Alloc>& lhs,
				const ft::map<Key, Tp, Compare, Alloc>& rhs)
	{
		return lhs._rbTree < rhs._rbTree;
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool
	operator!=(const ft::map<Key, Tp, Compare, Alloc>& lhs,
				const ft::map<Key, Tp, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool
	operator>(const ft::map<Key, Tp, Compare, Alloc>& lhs,
				const ft::map<Key, Tp, Compare, Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool
	operator<=(const ft::map<Key, Tp, Compare, Alloc>& lhs,
				const ft::map<Key, Tp, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool
	operator>=(const ft::map<Key, Tp, Compare, Alloc>& lhs,
				const ft::map<Key, Tp, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif