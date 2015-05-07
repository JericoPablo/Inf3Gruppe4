using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binaerbaum
{
    class MaxProblem : DivisibleProblem<MaxSolution>
    {
        protected MaxSolution solut;
        private BinaryTree tree;

        public MaxProblem(BinaryTree tree)
        {
            this.tree = tree;
            solut = new MaxSolution();
        }

        protected override void checkSolability()
        {
            if (tree != null)
                isDirectlySolvable = true;
            else
                isDirectlySolvable = false;
        }
        protected override void solve()
        {
            solut.maxValue = max(tree.rootNode);           
        }
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
        public int getSolution()
        {
            solve();
            return solut.maxValue;
        }
        public override MaxSolution Solution()
        {
            return solut;
        }
    }
}
