/**
 * This program is mean to be used with node passing the strings as parameters
 * to the program as Shown in the example. Any way, it can also be used in any
 * other environment by passing two strings to the `intersect` Function
 * as shown on its own example because the only part "node dependant" is the
 * getStringsFromArgs and the way the arguments are passed to `intersect`.
 * In node if you pass a quoted string instead of a single word you can make it
 * work on entire phrases. See the example #2
 * @example node ./CommonLetters.js Java Javascript // Between 'JavaScript' and 'Java' are 3 common characters: a, j, v
 * @example node ./CommonLetters.js "Never more, said Allan Poe" "Never more, said Freddie Mercury" // Between 'Never more, said Allan Poe' and 'Never more, said Freddie Mercury' are 10 common characters: a, d, e, i, m, n, o, r, s, v
 */

const getStringsFromArgs = args => {
  const str1 = args[2]
  const str2 = args[3]
  return [str1, str2]
}

const validChar = char => /[a-zA-Z]/.test(char)

/**
 *
 * @param {String} str1 The first string to compare
 * @param {String} str2 The seccond string to compare
 * @return {String[]} a set of chars that exist on both `str1` and `str2`
 * @example intersect('Java', 'Javascript') // ['a', 'j', 'v']
 */
const intersect = (str1, str2) => {
  const Set1 = str1.toLowerCase().split('')
  const Set2 = str2.toLowerCase().split('')

  return [...Set1, ...Set2]
    .reduce((acc, char) => {
      // Check if is a valid alphabetic char, no numbers, no symbols
      if (!validChar(char)) return acc
      // Check if exist in both strings but wasn't previously added
      if (Set1.includes(char) && Set2.includes(char) && !acc.includes(char))
        return [...acc, char]
      else return acc
    }, [])
    .sort()
}

const [str1, str2] = getStringsFromArgs(process.argv)
const commonChars = intersect(str1, str2)

// You can use a fancy library, like 'Chalk' or the Browser Console styles interface
// to make a very pretty print outta this
console.log(
  `Between '${str1}' and '${str2}' are ${
    commonChars.length
  } common characters: ${commonChars.join(', ')}`
)
