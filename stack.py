class stack:
	def __init__(self):
		self.stack=[]
	def push(self,dataval):
		if dataval not in self.stack:
			self.stack.append(dataval)
			return True
		else:
			return False
	def peek(self):
		return self.stack
	def pop(self):
		if len(self.stack) <=0 :
			return "stack underflow"
		else:
			return self.stack.pop()
AStack= stack()
i= int(raw_input("How many elements do you want to enter:"))
l=0
while l<i:
	p= raw_input('enter the string')
	AStack.push(p)
	l=l+1
print stack()
print AStack.pop()
print AStack.pop()
print AStack.pop()
print AStack.pop()
print stack()
