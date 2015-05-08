using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binaerbaum
{
    abstract class DivisibleProblem<S> : Problem<S>
    {
        /*returns true wehn problem is directly solvable*/
        protected Boolean isDirectlySolvable;
        /*is checking solvability*/
        protected abstract void checkSolability();
        /*solves problem*/
        protected abstract void solve();
    }
}
