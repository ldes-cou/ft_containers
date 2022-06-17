/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:06:09 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/17 17:46:49 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_NODE_HPP
#define RB_NODE_HPP

#define BLACK 0
#define RED 1

#ifndef VALUE_TYPE 
#define VALUE_TYPE int
namespace ft
{
	template <typename T>
	struct Node 
	{
		public:
			int         color;
			Node        *parent;
			Node     	*left_child;
			Node     	*right_child;
			VALUE_TYPE  key;
		
			
	}   
}
#endif