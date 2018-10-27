function isKaprekar(k) {
    var n = length(k);
    var square = k * k;

    var firstPeice = String(square).substring(0, length(square) - n);
    var secondPiece = String(square).substring(length(square) - n);

    var sumOfPieces = Number(firstPeice) + Number(secondPiece);
    
    var outputMessage = 
        'inputNumber: ' + k + ', ' +
        'Sum: ' + sumOfPieces;
    
    return {
        isKaprekar: sumOfPieces === k,
        explanation: outputMessage
    };
}

function length(value) {
    return String(value).length;
}


console.log(isKaprekar(45))