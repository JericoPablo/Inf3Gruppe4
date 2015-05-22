using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binaerbaum
{
    class MaxProblem : DivisibleProblem<MaxSolution>
    {
        /*variables*/
        protected MaxSolution solut;
        private BinaryTree tree;

        /*constructs a MaxProblem object*/
        public MaxProblem(BinaryTree tree)
        {
            this.tree = tree;
            solut = new MaxSolution();
        }
        /*overvrites explained method*/
        protected override void checkSolability()
        {
            if (tree != null)
                isDirectlySolvable = true;
            else
                isDirectlySolvable = false;
        }
        /*solves problem*/
        protected override void solve()
        {
            solut.maxValue = max(tree.rootNode);           
        }
        /*computs max of tree*/
        private int max(Node node)
        {
            int maximal = 0;
            if (node.getRight() == null)
                return node.nodeValue;
            while (node.getRight() != null)
            {

                node = node.getRight();
                maximal = node.nodeValue;
                
            }
            return maximal;
        }
        /*gets solution*/
        public int getSolution()
        {
            solve();
            return solut.maxValue;
        }
        /*does importent things*/
        public override MaxSolution Solution()
        {
            return solut;
        }
    }
}
