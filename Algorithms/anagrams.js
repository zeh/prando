const isAnagram = (function () {
    const sanitizeRegex = /[^a-z0-9]/gi;

    const sanitizeString = function (str) {
        return str.replace(sanitizeRegex, '').toLowerCase().split('').sort().join('');
    };

    return function (str1, str2) {
        return sanitizeString(str1) === sanitizeString(str2);
    };
}());

console.log(isAnagram('cinema', 'iceman'));