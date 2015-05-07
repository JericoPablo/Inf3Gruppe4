using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binaerbaum
{
    class MaxSolution : Solution
    {
        private int max;
        public int maxValue
        {
            get
            {
                return max;
            }
            set
            {
                this.max = value;
            }
        }
    }
}
