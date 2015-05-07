using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics.Contracts;

namespace Binaerbaum
{
    class BinaryTree
    {
        /*private variables*/
        private Node root;
        /*constructor*/
        public BinaryTree(int rootValue)
        {
            root = new Node(rootValue);
        }
        /*constructor*/
        public void insert(int value)
        {
            if (this.root == null)
                root = new Node(value);
            this.insertRecursion(this.root, value);
        }
        /*getter setter rootnode*/
        public Node rootNode
        {
            get
            {
                Contract.Requires(this.root != null);
                return this.root;
            }
            set
            {
                this.root = value;
            }

        }
        /*insert recursion for a node*/
        private void insertRecursion(Node node, int value)
        {
            Contract.Requires(node != null);
            if (node == null)
                node = new Node(value);
            if (this.root == null)
                this.root = node;
            else
            { 
               if (value < node.nodeValue)
                {
                    if (node.getLeft() != null)
                    {
                        this.insertRecursion(node.getLeft(),value);
                    }
                    else
                    {
                        node.setLeft(new Node(value,node));
                    }
                }
               if (value > node.nodeValue)
               {
                   if (node.getRight() != null)
                   {
                       this.insertRecursion(node.getRight(), value);
                   }
                   else
                   {
                       node.setRight(new Node(value,node));
                   }
               }
            }
        }
        /*get elements inorder*/
        public String inOrder()
        {
            Contract.Requires(this.root != null);
            return inOrderRecursion(this.root);
        }
        /*create string of elements inorder*/
        private String inOrderRecursion(Node node)
        {
            Contract.Requires(node != null);
            String s = "";
            if (node == null)
                return "leer";
            if (node.getLeft() != null)
                s = inOrderRecursion(node.getLeft());
            s += node.nodeValue + "  ";
            if (node.getRight() != null)
                s += inOrderRecursion(node.getRight());
            return s;
        }



        /*public String preOrder()
        {
            return preOrderRecursion(this.root);
        }

        private String preOrderRecursion(Node node)
        {
            if (node != null)
                Console.WriteLine(node.nodeValue);
            if (node.getLeft() != null)
               preOrderRecursion(node.getLeft());
            
            if (node.getRight() != null)
               preOrderRecursion(node.getRight());
            return "";
        }

         */

        /*deletes element*/
        public Boolean delete(int value)
        {
            Contract.Requires(this.root != null);
            return deleteRecursion(this.rootNode,value,null,false);
        }
        /*searches for element and deletes*/
        private Boolean deleteRecursion(Node node, int value, Node vather, Boolean isLeftFromVather)
        {
            Contract.Requires(node != null);
            if (node == null)
                return false;
            if (value == node.nodeValue)
            {
                //found: node so delet!
                //node is a sheet
                if ((node.getLeft() == null) && (node.getRight() == null))
                {
                    if (vather == null)
                        this.rootNode = null;
                    else
                        hengUnderVather(vather, isLeftFromVather, null);
                    return true;
                }
                //node has just a undernode on the right side
                if ((node.getLeft() == null) && (node.getRight() != null))
                {
                    if (vather == null)
                        root = node.getRight();
                    else
                        hengUnderVather(vather, isLeftFromVather, node.getRight());
                    return true;
                }
                //node has just a undernode on the left side
                if ((node.getLeft() != null) && (node.getRight() == null))
                {
                    if (vather == null)
                        root = node.getLeft();
                    else
                        hengUnderVather(vather, isLeftFromVather, node.getLeft());
                    return true;
                }
                //k has left and right a undernode
                //replace the content of the want to delete node with the smalest value
                //of the right part of the tree
                //delete the undernode
                Node x = getSmallest(node.getRight());
                delete(x.nodeValue);
                if (vather == null)
                {
                    x.setLeft(root.getLeft());
                    x.setRight(root.getRight());
                    root = x;
                }
                else
                {
                    x.setLeft(node.getLeft());
                    x.setRight(node.getRight());
                    hengUnderVather(vather, isLeftFromVather, x);
                }
            }
            //not found: search left
            if (value < node.nodeValue)
            {
                if (node.getLeft() == null)
                    return false;
                return deleteRecursion(node.getLeft(), value, node, true);
            }
            //not found: search right
            if (value > node.nodeValue)
            {
                if (node.getRight() == null)
                    return false;
                return deleteRecursion(node.getRight(), value, node, false);
            }
            return false;
        }
        /*returns smalles element*/
        private Node getSmallest(Node node)
        {
            Contract.Requires(node != null);
            if (node != null)
            {
                while (node.getLeft() != null)
                    node = node.getLeft();
            }
            return node;
        }
        /*puts element unther vather*/
        private void hengUnderVather(Node vather, Boolean left, Node node)
        {
            Contract.Requires(node != null);
            if (left)
                vather.setLeft(node);
            else
                vather.setRight(node);
        }
        /*starts a search for a element*/
        public Boolean has(int value)
        {
           return hasRecursion(value, this.root);
        }


        /*searches for a element*/
        private Boolean hasRecursion(int value, Node node)
        {
            Contract.Requires(node != null);
            Boolean b = false;
            if (node != null)
                if (node.nodeValue == value)
                    return true;
            if (node == null)
                return false;
            if (node.getLeft() != null)
                b = b|hasRecursion(value,node.getLeft());
            if (node.getRight() != null)
                b = b | hasRecursion(value, node.getRight());
            return b;
        }
    }
}
