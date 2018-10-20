//How to use:
//firstWord.IsAnagram(secondWord);


public static bool IsAnagram(this string firstWord, string secondWord)
  {
      if (firstWord.Length != secondWord.Length)
          return false;

      var listOfChar = secondWord.ToLower().ToList();
      firstWord = firstWord.ToLower();
      foreach (var c in firstWord)
      {
          if (listOfChar.Any(x => x.Equals(c)))
              listOfChar.Remove(c);
          else
              return false;
      }
      return !listOfChar.Any();
  }
