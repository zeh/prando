const sum = (n) => {
    let sumN=0;
    for(let i=0; i<n; i++)
        if(i%3 == 0 && i%5 == 0)
            sumN+=i;
    return sumN;
}

//call sum(n)