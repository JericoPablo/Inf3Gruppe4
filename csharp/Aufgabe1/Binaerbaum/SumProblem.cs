using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binaerbaum
{
    class SumProblem : DivisibleProblem<SumSolution>
    {
        /*variables*/
         protected SumSolution solut;
        private BinaryTree tree;

        /*constructs a sumproblem*/
        public SumProblem(BinaryTree tree)
        {
            this.tree = tree;
            solut = new SumSolution();
        }
        /*checking solvability*/
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
            solut.maxValue = sum(tree.rootNode);           
        }
        /*creates sum of tree*/
        private int sum(Node node)
        {
            int summ = 0;
            if (node == null)
            {
                summ += 0;
            }
            if (node.getLeft() != null)
            {
                summ += sum(node.getLeft());
            }
            summ += node.nodeValue;
            if (node.getRight() != null)
            {
                summ += sum(node.getRight());
            }
            return summ;
        }
        /*retuns solution*/
        public int getSolution()
        {
            solve();
            return solut.maxValue;
        }
        /*returns solution*/
        public override SumSolution Solution()
        {
            return solut;
        }
    }
}
