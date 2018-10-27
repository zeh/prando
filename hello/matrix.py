#coding: utf-8
import sys


def MatrixOrder(p):
    n = len(p)-1
    r, d = {}, {}
    for i in range(1, n+1):
        r[str(i)+','+str(i)] = 0
    for l in range(2, n+1):
        for i in range(1, n-l+2):
            j = i+l-1
            r[str(i)+','+str(j)] = sys.maxint
            for k in range(i, j):
                q = r[str(i)+','+str(k)]+r[str(k+1)+','+str(j)]+p[i-1]*p[k]*p[j]
                if q<r[str(i)+','+str(j)]:
                    r[str(i)+','+str(j)] = q
                    d[str(i)+','+str(j)] = k
    return r, d
def OptimalParenthesis(s, i, j):
    result = ''
    if i == j:
        return "A"+str(j)
    else:
        result += "("
        result += OptimalParenthesis(s, i, s[str(i)+','+str(j)])
        result += OptimalParenthesis(s, s[str(i)+','+str(j)]+1, j)
        result +=  ")"
        return result
p = [int(m) for m in input.split()]
#p=[1,2,3]
r, d = MatrixOrder(p)
print 'min multiplications：', r[str(1)+','+str(len(p)-1)]
print 'parenthesisation', OptimalParenthesis(d, 1, len(p)-1)
