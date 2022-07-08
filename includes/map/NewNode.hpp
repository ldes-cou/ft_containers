/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:54:03 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/07/08 16:53:55 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#define BLACK 0
#define RED 1

namespace ft
{
	template <typename T>
		struct RB_Node
		{
			public :
				typedef T 																value_type;
				typedef RB_Node<T>														Node;
				typedef RB_Node<T>*     												Node_ptr;
				typedef const RB_Node*													_Const_Base_ptr;
				typedef	std::allocator<Node>											allocator_type;
				typedef typename allocator_type::template rebind<Node>::other			node_alloc;

			/******************************** MEMBER VARIABLES **********************************/
				//private:
					Node_ptr		parent;
					Node_ptr		left;
					Node_ptr		right;
					value_type		data;
					Node_ptr		T_nil;
					int 			color;
					

		    /************************************ CONSTRUCTOR ************************************/
			
                
    };
}
#endif