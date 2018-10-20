using System;

namespace CaseChange {
  class CaseChange {
    static void Main(string[] args){
      // args[0] is the input
      string newString = "";
      string oldString = args[0];

      for (int i = 0; i < oldString.Length; i++) {
        // Change case to lower if upper
        if (Char.IsUpper(oldString[i])){
          newString += Char.ToLower(oldString[i]);
        }
        // Otherwise, case to upper
        else {
          newString += Char.ToUpper(oldString[i]);
        }
      }
      Console.WriteLine(newString);
    }
  }
}