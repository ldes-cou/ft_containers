/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:06:09 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/16 13:59:14 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_NODE_HPP
#define RB_NODE_HPP

#define BLACK 0
#define RED 1

namespace ft
{
	template <typename T>
	struct Node 
	{
		public:
		
			typedef T                   value_type;
			typedef T&                  value_ref;
			typedef T*                  value_ptr;
			typedef Node<T>          	node_type;
			typedef Node<T>&         	node_ref;
			typedef Node<T>*         	node_ptr;
			typedef const T&            const_value_ref;
			typedef const T*            const_value_ptr;
			typedef const Node<T>&   	const_node_ref;
			typedef const Node<T>*   	const_node_ptr;
	
		private:
			typedef std::allocator<node_type>   alloc;
			
		public:
			int         color;
			Node        *parent;
			Node     	*left_child;
			Node     	*right_child;
			value_type  key;
		
			
	}   
}