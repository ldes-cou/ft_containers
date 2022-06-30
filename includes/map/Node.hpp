/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucrece <lucrece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:35:45 by lucrece           #+#    #+#             */
/*   Updated: 2022/06/30 14:47:09 by lucrece          ###   ########.fr       */
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

			/******************************** MEMBER VARIABLES**********************************/
				//private:
					
					Node_ptr		left;
					Node_ptr		right;
					Node_ptr		parent;
					value_type		data;
					int 			color;

		/********************************** CONSTRUCTOR **********************************/

		RB_Node(void): data(T())
		{
			this->color = BLACK;
			left = right = parent = NULL;
		}
		RB_Node(value_type data) :
            data(data)
		{
			// this->dat/a = data;
			left = right = parent = NULL;
			this->color = RED;
		}
        RB_Node const &operator=(const RB_Node& src)
        {
            *this = src;
        }
		~RB_Node()
		{}
		// Node(_Base_ptr parent  = 0 _Base_ptr left = 0, _Base_ptr right = 0, color = RED) : data(T())
		// {;
		// }
		
		// Node(const &Node cpy) : 
		// 	parent(cpy.parent), 
		// 	left(cpy.left), 
		// 	right(cpy.right), 
		// 	data(cpy.data),
		// 	color(cpy.color) // not sure for the color
		// {}
		// returns pointer to uncle
		RB_Node *uncle()
		{
			// If no parent or grandparent, then no uncle
			if (parent == NULL or parent->parent == NULL)
				return NULL;
			if (parent->isOnLeft())
				return parent->parent->right;
			else
				return parent->parent->left;
		}
		
			
	// check if node is left child of parent
			bool isOnLeft() { return this == parent->left; }

			// returns pointer to sibling
			Node *sibling() {
				// sibling null if no parent
				if (parent == NULL)
				return NULL;

				if (isOnLeft())
				return parent->right;

				return parent->left;
			}

			// moves node down and moves given node in its place
			void moveDown(Node *nParent) {
				if (parent != NULL) {
				if (isOnLeft()) {
					parent->left = nParent;
				} else {
					parent->right = nParent;
				}
				}
				nParent->parent = parent;
				parent = nParent;
			}

			bool hasRedChild()
			{
				return (left != NULL and left->color == RED) or
					(right != NULL and right->color == RED);
			}
            
        };
    };
        
#endif