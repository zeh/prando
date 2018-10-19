/**
 * @param {string} input - String to match against
 * @param {boolean} ignoreSpace - Option to ignore space character
*/

export function findFirstNonRepeatingCharacter(input, ignoreSpace = false) {
    for (let i = 0; i < input.length; i++) {
        if (input.match(new RegExp(input[i], "g")).length === 1) {
            if (input[i] === ' ' && !ignoreSpace) return input[i];
        }
    }
    return null;
}
