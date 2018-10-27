#add=round(add+round(delayfloat))
#print add/30
#ExpDelay_serverQ= delay()
#print ExpDelay_serverQ
import random
import math
rate=int(raw_input("Enter rate for the server side:"))
#add=0
rate1=int(raw_input("Enter rate for the client side:"))

delayone=[]
delaytwo=[]
for i in range(0,4):
	x=random.uniform(0,1)
	y=random.uniform(0,1)
	delayfloat= -math.log(1-x)*rate
	delayfloat2= -math.log(1-y)*rate1
	delay=round(delayfloat)
	delay2=round(delayfloat2)
	delayone.append(delay)
	#print delay_1
	delaytwo.append(delay2)
print delayone
print delaytwo
#import Delay
#ExpDelay_serverQ=Delay.delay
#ExpDelay_clientQ=Delay.delay1
serverQueue=[]
clientQueue=[]
#serverQueue.append(1)
#serverQueue.append(2)
#serverQueue.append(4)
print "MKL"
duplicatep=0
mainclk=[1,2,3,4,5]
for i1 in mainclk:
	duplicatep = 0
	print i1
#print serverQueue
	for i in delayone:
		print i 
		packetS=i1+i
		print "packetS which is going towards the server"
		print packetS
		serverQueue.append(packetS)
		print "after insertion of packetS server queue "
		#print len(serverQueue)
		print serverQueue
	#	for i in mainclk:
		print i1	
		if i1 in serverQueue:
			print i
			serverQueue.remove(i1)
			duplicatep+=1
			print "duplicatep"
			print duplicatep
			print clientQueue
			while (duplicatep>0):
				
				for i3 in delaytwo:
					packetC=i1+i3
					clientQueue.append(packetC)
						
					duplicatep-=1
					print len(clientQueue)
			
					print clientQueue
				
					if i1 in clientQueue:
						while clientQueue.remove(i1):
							print "after dept queue  size"
							print len(clientQueue)
							print clientQueue
				print "after dept server queue size"
				print len(serverQueue)
				print serverQueue
		
