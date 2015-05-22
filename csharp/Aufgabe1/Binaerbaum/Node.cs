using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics.Contracts;


namespace Binaerbaum
{
    class Node
    {
        /*variables*/
        private int value;
        private Node left = null;
        private Node right = null;
        private Node parent = null;
        private Boolean markiert = false;


        /*onstructor*/
       public  Node(int value)
        {
            this.nodeValue = value;
        }

       /*consturctor*/
       public Node(int value, Node parent)
       {
           Contract.Requires(parent != null);
           this.nodeValue = value;
           this.parent = parent;
           Contract.Ensures(parent != null);
       }

       /*getter setter for nodevalue*/
        public int nodeValue
       {
           get
           {
               return value;
           }
           set
           {
               this.value = value;
           }

       }
        /*get leftchild*/
       public Node getLeft()
       {
           Contract.Ensures(this.left != null);
           return this.left;
       }

       /*set left child*/
        public void setLeft(Node n)
       {
           Contract.Requires(n != null);
            this.left = n;
       }
        /*get rightchild*/
        public Node getRight()
       {
           Contract.Ensures(this.right != null);
           return this.right;
       }
        /*set right child*/
       public void setRight(Node n)
       {
           Contract.Requires(n != null);
           this.right = n;
       }
       /*set mark*/
       public void setMark(Boolean mark)
       {
           this.markiert = mark;
           Contract.Ensures(this.markiert == mark);
       }
       /*check mark*/
       public Boolean isMarked()
       {
           return this.markiert;
       }
       /*set parent*/
       public void setParent(Node node)
       {
           Contract.Requires(node != null);
           this.parent = node;
       }

       /*get parent*/
       public Node getParent()
       {
           Contract.Requires(this.parent != null);
           return this.parent;
       }
    }
}
