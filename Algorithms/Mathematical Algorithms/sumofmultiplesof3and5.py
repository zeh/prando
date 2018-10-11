def sumof3and5(N):
    an_of3 = N - N % 3
    an_of5 = N - N % 5                          #Checks last natural number divisible by 3, 5 and 15
    an_of15 = N - N % 15
    n_of3 = an_of3 / 3
    n_of5 = an_of5 / 5                          #Checks how many times its divisible by 3, 5 and 15
    n_of15 = an_of15 / 15
    S_of3 = ((3 + (an_of3)) / 2) * n_of3
    S_of5 = ((5 + (an_of5)) / 2) * n_of5        #Sums up series of 3, 5 and 15
    S_of15 = ((15 + (an_of15)) / 2) * n_of15  
    return int(S_of3 + S_of5 - S_of15)