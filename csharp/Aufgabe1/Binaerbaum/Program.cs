using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binaerbaum
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree baum = new BinaryTree(10);
            
            baum.insert(24);
            baum.insert(15);
            baum.insert(5);
            baum.insert(2);    
            baum.insert(18);
            baum.insert(7);


            Console.WriteLine("inOrder: "+ baum.inOrder());
            Console.WriteLine(baum.has(15));
            
            baum.delete(15);
            Console.WriteLine("inOrder: " + baum.inOrder());
            Console.WriteLine(baum.has(15));

            /*
            baum.delete(5);
            Console.WriteLine("inOrder: " + baum.inOrder());
            baum.delete(5);
            Console.WriteLine("inOrder: " + baum.inOrder());
            */

            MaxProblem m = new MaxProblem(baum);
            Console.WriteLine(m.getSolution());

            Console.ReadLine();

        }
    }
}
