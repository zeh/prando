/*
 * Function that will accept an amount of money in dollar form (ex 99.99) and break it down
 * into the common bills and coins using simple mathematical operations.
 */
 
function calc(money) {
  // separate dollars and cents to avoid float calculations
  var dollar = Math.floor(money/1);
  var cent = ((money-dollar)*100).toFixed(0);
  
  // division and modulus operations determine the number of each bill and coin
  // bills
  var twenty = Math.floor(dollar/20);
  dollar = dollar%20;
  var ten = Math.floor(dollar/10);
  dollar = dollar%10;
  var five = Math.floor(dollar/5);
  dollar = dollar%5;
  var one = dollar;
  // coins
  var quarter = Math.floor(cent/25);
  cent = cent%25;
  var dime = Math.floor(cent/10);
  cent = cent%10;
  var nickel = Math.floor(cent/5);
  cent = cent%5;
  var penny = cent;
}
