# Remove Vowels from string

def remove_vowel(string)
  vowels = ['a', 'e', 'i', 'o', 'u']
  puts (string.downcase.split('') - vowels).join('')
end

remove_vowel 'This is test text'
