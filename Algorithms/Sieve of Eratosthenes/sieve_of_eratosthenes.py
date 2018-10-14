def eratosthenes_sieve(limit):
    sieve = [True] * (limit+1)                      # Initialize the primality list
    sieve[0] = sieve[1] = False
    result = []                                     # Result list of prime numbers in given range
    for i in range(2, limit+1):
        if sieve[i]:
            result.append(i)                        # append primary number to result list
            for k in range(2, int(limit/i)+1):      # mark folowing non-primary numbers 
                sieve[i*k] = False
    return result                                   # yield the resulting list of primary numbers

# print eratosthenes_sieve(101)

