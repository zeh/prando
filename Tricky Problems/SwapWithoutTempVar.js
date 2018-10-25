interface Numbers {
  first: Number,
  second: Number
}

function swapWithoutTempVar(input: Numbers): Numbers {
  input.second = input.first + input.second;
  input.first = input.second - input.first;
  input.second = input.second - input.first;
  
  return input;
}

console.log(swapWithoutTempVar({first: 3, second:5}));
