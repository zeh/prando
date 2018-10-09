#for finding Greatest Common Divisor of two numbers using pyhton
def gcd(a,b):
    if a==0:
        return(b)
    else:
	return(b%a,a)
