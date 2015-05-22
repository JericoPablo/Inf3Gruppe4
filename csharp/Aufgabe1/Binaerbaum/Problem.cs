using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binaerbaum
{
    abstract class Problem<S> : Solution
    {
        public abstract S Solution();
    }
}
