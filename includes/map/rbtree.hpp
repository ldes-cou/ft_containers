/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:31:50 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/06/20 17:23:14 by ldes-cou         ###   ########.fr       */
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

//set a T.nil sentinel to deal with iterators

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
    ~Node()
    {;}
    
};

class RBTree
{
    private:
    
        Node    *root;
        //Node     *Tnill;

    public:
    
        RBTree()
        {
            root = NULL;
            //Tnill = NULL;
        }
        ~RBTree(){}    
        void insert(const int &data)
        {
            Node *ptr = new Node(data);
            
            root = BSTInsert(root, ptr);
            insertFix(root, ptr);
        }
        
        void insertFix(Node *&root, Node *&pt)
        {
            Node *parent_pt = NULL;
            Node *grand_parent_pt = NULL;
        
            while ((pt != root) && (pt->color != BLACK) &&
                (pt->parent->color == RED))
            {
        
                parent_pt = pt->parent;
                grand_parent_pt = pt->parent->parent;
        
                /*  Case : A
                    Parent of pt is left child
                    of Grand-parent of pt */
                if (parent_pt == grand_parent_pt->left)
                {
        
                    Node *uncle_pt = grand_parent_pt->right;
        
                    /* Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                    if (uncle_pt != NULL && uncle_pt->color ==
                                                        RED)
                    {
                        grand_parent_pt->color = RED;
                        parent_pt->color = BLACK;
                        uncle_pt->color = BLACK;
                        pt = grand_parent_pt;
                    }
        
                    else
                    {
                        /* Case : 2
                        pt is right child of its parent
                        Left-rotation required */
                        if (pt == parent_pt->right)
                        {
                            rotateLeft(root, parent_pt);
                            pt = parent_pt;
                            parent_pt = pt->parent;
                        }
        
                        /* Case : 3
                        pt is left child of its parent
                        Right-rotation required */
                        rotateRight(root, grand_parent_pt);
                        std::swap(parent_pt->color,
                                grand_parent_pt->color);
                        pt = parent_pt;
                    }
                }
        
                /* Case : B
                Parent of pt is right child
                of Grand-parent of pt */
                else
                {
                    Node *uncle_pt = grand_parent_pt->left;
        
                    /*  Case : 1
                        The uncle of pt is also red
                        Only Recoloring required */
                    if ((uncle_pt != NULL) && (uncle_pt->color ==
                                                            RED))
                    {
                        grand_parent_pt->color = RED;
                        parent_pt->color = BLACK;
                        uncle_pt->color = BLACK;
                        pt = grand_parent_pt;
                    }
                    else
                    {
                        /* Case : 2
                        pt is left child of its parent
                        Right-rotation required */
                        if (pt == parent_pt->left)
                        {
                            rotateRight(root, parent_pt);
                            pt = parent_pt;
                            parent_pt = pt->parent;
                        }
        
                        /* Case : 3
                        pt is right child of its parent
                        Left-rotation required */
                        rotateLeft(root, grand_parent_pt);
                        std::swap(parent_pt->color,
                                grand_parent_pt->color);
                        pt = parent_pt;
                    }
                }
            }
        
            root->color = BLACK;
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
            node->parent = node_right;
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

        /************************************ TOOLS *****************************************/
        Node *maximum(Node *node) 
        {
            while (node->right != NULL) {
            node = node->right;
            }
            return node;
        }

        Node *successor(Node *x) 
        {
            if (x->right != NULL) 
                return minimum(x->right);
            Node *y = x->parent;
            while (y != NULL && x == y->right) 
            {
                x = y;
                y = y->parent;
            }
            return y;
        }

        Node *predecessor(Node *x)
        {
            if (x->left != NULL) 
                return maximum(x->left);

            Node *y = x->parent;
            while (y != NULL && x == y->left) 
            {
                x = y;
                y = y->parent;
            }
            return y;
        }
        Node *minimum(Node *node)
        {
            while (node->left != NULL) 
                node = node->left;
            return node;
        }

        Node *maximum(Node *node) 
        {
            while (node->right != NULL) 
                node = node->right;
            return node;
        }
        void rbTransplant(Node* u, Node* v)
        {
            if (u->parent == nullptr)
            {
                root = v;
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
        /*********************************** DELETE ******************************************/
        void deleteFix(Node *x)
        {
            Node *s;
            while (x != root && x->color == 0) 
            {
                if (x == x->parent->left)
                {
                    s = x->parent->right;
                    if (s->color == 1)
                    {
                        s->color = 0;
                        x->parent->color = 1;
                        rotateLeft(root, x->parent);
                        s = x->parent->right;
                    }

                    if (s->left->color == 0 && s->right->color == 0)
                    {
                        s->color = 1;
                        x = x->parent;
                    }
                    else 
                    {
                        if (s->right->color == 0)
                        {
                            s->left->color = 0;
                            s->color = 1;
                            rotateRight(root, s);
                            s = x->parent->right;
                        }
                        s->color = x->parent->color;
                        x->parent->color = 0;
                        s->right->color = 0;
                        rotateLeft(root, x->parent);
                        x = root;
                    }
                    } 
                else 
                {
                    s = x->parent->left;
                    if (s->color == 1)
                    {
                        s->color = 0;
                        x->parent->color = 1;
                        rotateRight(root, x->parent);
                        s = x->parent->left;
                    }
                    if (s->right->color == 0 && s->right->color == 0)
                    {
                        s->color = 1;
                        x = x->parent;
                    }
                    else
                    {
                        if (s->left->color == 0) 
                        {
                            s->right->color = 0;
                            s->color = 1;
                            rotateLeft(root, s);
                            s = x->parent->left;
                        }
                        s->color = x->parent->color;
                        x->parent->color = 0;
                        s->left->color = 0;
                        rotateRight(root, x->parent);
                        x = root;
                    }
                }
                x->color = 0;
            }
        }

        void deleteNodeHelper(Node* node, int key)
        {
            Node *z = NULL;
            Node *x;
            Node *y;
            while (node != NULL) 
            {
                if (node->data == key)
                    z = node;
                if (node->data <= key)
                    node = node->right;
                else
                    node = node->left;
            }

            if (z == NULL)
            {
                std::cout << "Key not found in the tree" << std::endl;
                return;
            }

            y = z;
            int y_original_color = y->color;
            if (z->left == NULL)
            {
                x = z->right;
                rbTransplant(z, z->right);
            }
            else if (z->right == NULL)
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
                    x->parent = y;
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
            delete z;
            if (y_original_color == 0) 
            {
                //deleteFix(x);
            }
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