using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binaerbaum
{
    abstract class DivisibleProblem<S> : Problem<S>
    {
        protected Boolean isDirectlySolvable;
        protected abstract void checkSolability();
        protected abstract void solve();
    }
}
