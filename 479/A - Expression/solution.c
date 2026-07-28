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
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int c = int.Parse(Console.ReadLine());
            int ans = (a + b) * c;
            ans = Math.Max(ans, a * (b + c));
            ans = Math.Max(ans, a + b + c);
            ans = Math.Max(ans, a * b * c);
            ans = Math.Max(ans, a * b + c);
            ans = Math.Max(ans, a + b * c);
            ans = Math.Max(ans, a * (b + c));
            ans = Math.Max(ans, (a + b) * c);
            Console.WriteLine(ans);
        }
    }
}