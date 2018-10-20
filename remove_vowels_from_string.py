vowels = ['a', 'i', 'e', 'y', 'o', 'u']

print("".join(
            filter(
                lambda x: x not in vowels,
                input().lower())))
