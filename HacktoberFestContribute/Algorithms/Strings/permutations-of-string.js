function *stringPermutation(arr, len = arr.length) {
    if (len <= 1) yield arr.slice();
    else for (let i = 0; i < len; i++) {
      yield *stringPermutation(arr, len - 1);
      const j = len % 2 ? 0 : i;
      [arr[len-1], arr[j]] = [arr[j], arr[len-1]];
    }
  }
  
  console.log(Array.from(stringPermutation("xyz".split(''))).map(perm => perm.join('')));