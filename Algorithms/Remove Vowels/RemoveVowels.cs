using System;
using System.Text.RegularExpressions;

namespace RemoveVowels
{
    class RemoveVowels
    {
        static void Main(string[] args)
        {
          // args[0] is the input
          string removedVowels = Regex.Replace(args[0], @"[aeiouyAEIOUY]", "");
          Console.WriteLine(removedVowels);
        }
    }
}
