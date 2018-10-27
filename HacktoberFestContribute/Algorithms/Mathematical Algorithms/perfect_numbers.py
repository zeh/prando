import sys

def divisors(x):
    return [y for y in range(1, int(x / 2) + 1) if x % y == 0]
 
def perfect_numbers_in_range(a,b):
    return [x for x in range(a,b+1) if sum(divisors(x)) == x]
 
if __name__ == "__main__":
    print(perfect_numbers_in_range(int(sys.argv[1]), int(sys.argv[2])))
