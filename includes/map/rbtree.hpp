/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:31:50 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/17 18:17:05 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#define BLACK 0
#define RED 1
#include <cstddef>
#ifndef VALUE_TYPE 
#define VALUE_TYPE int
namespace ft;
{
    template<typename T>
    struct Node 
    {
        T key;
        Node *parent;
        Node *left;
        Node *right;
        int color;
    };
    class RedBlackTree
    {
        Node *root;
        Node *nill;
        
    void rb_tree_init(Node* node, Node* parent) 
    {
        node->key = BLACK;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = BLACK;
    }
        
        void insert(T new_key)
        {
            NodePtr new_node = new Node;
            new_node->parent = nullptr;
            new_node->key = new_key;
            new_node->right = nill;
            new_node->left = nill;
            new_node->color = RED;

            Node  *y = nullptr;
            Node  *x = this->root;
            while (x != nill)
            {
                y = x;
                if (new_node->key < x->key)
                    x = x->left;
                else
                    x = x->right;
                new_node->parent = y;
                if (y == nullptr)
                    root = new_node;
                else if (new_node->key < y->key)
                    y->left = new_node;
                else
                    y->right = new_node;
            }
            if (new_node->parent == nullptr)
            {
                new_node->color = BLACK;
                return;
            }
            if (new_node->parent->parent == nullptr)
                return;
            //insertFix(new_node)
        }
    }
    
}

#endif
#endif