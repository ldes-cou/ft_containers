/**
			 * @brief Single element.
			 * The vector is extended by inserting new elements
			 * before the element at the specified position,
			 * effectively increasing the container size by the number
			 * of elements inserted.
			 *
			 * @param position Position in the vector where the new elements are inserted.
			 * @param val Value to be copied (or moved) to the inserted elements.
			 * @return An iterator that points to the first of the newly inserted elements.
			 */
			iterator	insert ( iterator position, const value_type& val )
			{
				size_type	insert_idx = ft::distance(this->begin(), position);

				this->reserve(computeCapacity(1));
				iterator new_pos = this->begin() + insert_idx;
				iterator it = this->end();
				size_type i = this->size();
				while (it != new_pos)
				{
					_alloc.construct(this->_start + i, this->_start[i - 1]);
					_alloc.destroy(this->_start + i - 1);
					i--;
					it--;
				}
				_alloc.construct(this->_start + i, val);
				this->_end++;
				return (iterator(this->_start + insert_idx));
			}

			/**
			 * @brief Fill.
			 * The vector is extended by inserting new elements
			 * before the element at the specified position,
			 * effectively increasing the container size by the number
			 * of elements inserted.
			 *
			 * @param position Position in the vector where the new elements are inserted.
			 * @param n Number of elements to insert.
			 * @param val Value to be copied (or moved) to the inserted elements.
			 */
			void		insert ( iterator position, size_type n, const value_type& val )
			{
				if (n == 0)
					return ;
				size_type	new_size = this->size() + n;
				size_type	new_start	= ft::distance(this->begin(), position);
				ptrdiff_t	i			= this->size() - 1;
				size_type	j;
				this->reserve(computeCapacity(n));
				while (i >= static_cast<ptrdiff_t>(new_start))
				{
					this->_alloc.construct(this->_start + n + i, this->_start[i]);
					this->_alloc.destroy(this->_start + i);
					i--;
				}
				j = 0;
				while (j < n)
				{
					this->_alloc.construct(this->_start + new_start + j, val);
					j++;
				}
				this->_end = this->_start + new_size;
			}

			/**
			 * @brief Range.
			 * The vector is extended by inserting new elements
			 * before the element at the specified position,
			 * effectively increasing the container size by the number
			 * of elements inserted.
			 *
			 * @param position Position in the vector where the new elements are inserted.
			 * @param first Input iterators to the initial position in a sequence
			 * @param last Input iterators to the final position in a sequence
			 */
			template <class InputIterator>
    		void		insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_type	dist = ft::distance(first, last);
				if (dist == 0)
					return ;
				size_type	new_size = this->size() + dist;
				size_type	insert_idx	= ft::distance(this->begin(), position);
				ptrdiff_t	i			= this->size() - 1;
				InputIterator	tmp;
				this->reserve(computeCapacity(dist));
				while (i >= static_cast<ptrdiff_t>(insert_idx))
				{
					this->_alloc.construct(this->_start + dist + i, this->_start[i]);
					this->_alloc.destroy(this->_start + i);
					i--;
				}
				tmp = first;
				i = 0;
				while (tmp != last)
				{
					this->_alloc.construct(this->_start + insert_idx + i, *tmp);
					tmp++;
					i++;
				}
				this->_end = this->_start + new_size;
			}