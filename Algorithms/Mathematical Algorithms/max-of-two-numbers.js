// max of two numbers without using comparative operators or if else
function max(x, y) 
{ 
  return x ^ ((x ^ y) & -(x < y));  
} 

console.log(max(100, 15));