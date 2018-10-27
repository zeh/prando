#!/usr/bin/env python3
from math import gcd
import gmpy2
from Crypto.PublicKey import RSA
from Crypto.Util.number import *
'''RSA Implementation in python 3.6 '''
# Two random prime numbers are chosen
p=2
q=7
n=p*q
phi=(p-1)*(q-1)

print("Choosen primes:")
print("p=",p, ", q =",q)
print("Modulus or n =",n)
print("Euler's Function (totient) [phi(n)]:",phi)

# find ecryption key a coprime between 1<e<$phi such that gcd (e,phi)==1
e=2  # we start with 2 for minimum..  this is normally 65537
while(e<phi):
    if gcd(e,phi)==1:
        break

    else:
        e=e+1

e=int(e)
print("Encryption key", e)

# Private key (d stands for decrypt)
# choosing d such that it satisfies
# d*e = 1 + k * totient(phi)

d = inverse(e,phi)

msg=2
#converting string to hex because we need integers to encrypt
print("Message to be encrypted",msg)
#Encryption Algo :=  encr_msg= ((msg)^e)%n
# Hopefully, the inbuilt `pow` method of python does this for us in 3 args
enc_msg=pow(msg,e,n)

print ("Encrypted message",enc_msg)

print("Decrypting the message with key", d)

dec_msg=pow(enc_msg,11,n)

print("Decrypted message is", dec_msg)

