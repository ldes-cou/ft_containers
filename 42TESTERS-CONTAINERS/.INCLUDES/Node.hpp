/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:35:45 by lucrece           #+#    #+#             */
/*   Updated: 2022/07/12 11:38:57 by ldes-cou         ###   ########.fr       */
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
			
					Node_ptr		parent;
					Node_ptr		left;
					Node_ptr		right;
					value_type		data;
					Node_ptr		T_nil;
					int 			color;
					

		    /************************************ CONSTRUCTOR ************************************/
		public:
		
		RB_Node(void): data(T())
		{
			parent = NULL;
			left =  NULL;
			right = NULL;
			color = 0;
			T_nil = NULL;
			
		}
		
		RB_Node(value_type data, Node_ptr const &Tnil) :
            data(data),
			T_nil(Tnil)
		{
			parent = NULL;
			left = NULL;
			right = NULL;
		}
		
        RB_Node const &operator=(const RB_Node& src)
        {
            *this = src;
        }
		~RB_Node()
		{}
		
		RB_Node(const RB_Node &cpy) : 
			parent(cpy.parent), 
			left(cpy.left), 
			right(cpy.right), 
			data(cpy.data),
			color(cpy.color)
		{}

        };
    };
        
#endif