using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args) {
            int t = 1;
            //t = int.Parse(Console.ReadLine());
            while (t-- != 0) {
                Solve();
            }
        }
        public static void Solve() {
            string s = Console.ReadLine();
            string r = Console.ReadLine();
            string revs = string.Concat(s.Reverse());
            if (r == revs) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }
}