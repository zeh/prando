export function findFirstNonRepeatingCharacter(input: string, ignoreSpace?: boolean): string {
    for (let i = 0; i < input.length; i++) {
        if (input.match(new RegExp(input[i], 'g')).length === 1) {
            if (input[i] === ' ' && !ignoreSpace) return input[i];
        }
    }
    return null;
}