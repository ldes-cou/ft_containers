/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:31:50 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/20 12:30:46 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#define BLACK 0
#define RED 1
#define B = "\x1b[30m"
#define R = "\x1b[31m"
# define END "\033[0m"
#include <cstddef>
#include <iostream>
#ifndef VALUE_TYPE 
#define VALUE_TYPE int

#define out(x) std::cout << x << std::endl;

//template<typename T>
struct Node 
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
    bool color;

    Node(int data)
    {
        this->data = data;
        left = right = parent = NULL;
        this->color = RED;
    }
    
};

class RBTree
{
    private:
    
        Node    *root;
        //Node     *nill;

    public:
    
        RBTree()
        {
            root = NULL;
        }
        //~RBTree(){}    
        void insert(const int &data)
        {
            Node *ptr = new Node(data);
            
            root = BSTInsert(root, ptr);
            //insertFix(root, ptr);
        }
        void insertFix(Node *&root, Node *&node)
        {
            Node *parent = NULL;
            Node *gd_parent = NULL;
            
            while ((node != root) && (node->color != BLACK) && node->parent->color == RED))
            {
                parent = node->parent;
                gd_parent = node->parent->parent;
            }
            /*  CASE : A
                node's parent is left child 
                of node's gd parent
            */
            if (parent == gd_parent->left)
            {
                Node *uncle = gd_parent->right;
                
                /* CASE :1
                
            }  
        }
        /******************************************** INSERT ***********************************************/
        Node *BSTInsert(Node * root, Node *ptr)
        {
            /* if root is empty return  a new node */
            if (root == NULL)
                return ptr;
            /* otherwise, recur down the tree */
            if (ptr->data < root->data)
            {
                root->left = BSTInsert(root->left, ptr);
                root->left->parent = root;
            }
            else if (ptr->data > root->data)
            {
                root->right = BSTInsert(root->right, ptr);
                root->right->parent = root;
            }
            /* return the unchanged  node pointer */
            return (root);    
        }
        
        /*********************************** ROTATIONS **************************************/

        void rotateLeft(Node *&root, Node *&node)
        {
            Node *node_right = node->right;
            node->right = node_right->left;

            if (node->right != NULL)
                node->right->parent = node;
            node_right->parent = node->parent;
            if (node->parent == NULL)
                root = node_right;
            else if (node == node->parent->left)
                node->parent->left = node_right;
            else
                node->parent->right = node_right;
            node_right->left = node;
            ptr->paretn = node_right;
        }
        
        void rotateRight(Node *&root, Node *&node)
        {
            Node *node_left = node->left;
            
            node->left = node_left->right;
            if ( node->left != NULL )
                node->left->parent = node;
            node_left->parent = node->parent;
            if ( node->parent == NULL )
                root = node->left;
            else if ( node == node->parent->left)
                node->parent->left = node_left;
            else
                node->parent->right = node_left;
            node_left->right = node;
            node->parent = node_left;
        }
        
        /***********************************   PRINT  ***************************************/
        void print(Node *root, std::string indent, bool last)
        {
            if (root != NULL)
            {
                std::cout << indent;
                if (last)
                {
                    std::cout << "R----";
                    indent += "    ";
                }
                else
                {
                    std::cout << "L----";
                    indent += "|   ";
                }
                std::string sColor;
                if (root->color == RED)
                {
                    sColor = "\x1b[31m";
                    //out("ICI");
                }
                else
                {
                    sColor = "\x1b[30m";
                    //out("LA");
                }
                std::cout << sColor << "(" << root->data  << ")" << END << std::endl;
                print(root->left, indent,false);
                print(root->right, indent, true);
            }
        }
        void printTree()
        {
            //out("THERE");
            if (root)
            {
                print(this->root, "", true);
                //out(this->root->key);
            }
        }
    
};


#endif
#endif