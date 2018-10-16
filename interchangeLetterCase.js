alert(
  prompt('Input a string')
  .split('')
  .map(
    v => {
      let char = v.charCodeAt(0)

      if ( char >= 65 && char <= 90 )
        char+=32
      else if ( char >= 97 && char <= 122 )
        char-=32

      return String.fromCharCode(char)
    }
  )
  .join('')
)
