  public static char? FirstNonRepeatingCharacter(this string word)
  {
      word = word.ToLower();
      foreach (var c in word)
      {
          if (word.Count(x => x.Equals(c)) > 1)
              return c;
      }

      return null;
  }
