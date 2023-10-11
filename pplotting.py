import numpy as np
import scipy
import matplotlib.pyplot as plt
from random import *
from math import pi


# N=20
# with open("trajectoire.txt") as f:
#     lines = f.readlines()[0:N]
#     x = [line.split(' ')[0] for line in lines]
#     y = [line.split(' ')[1] for line in lines]

# with open("trajectoire with noise.txt") as f:
#     lines = f.readlines()[0:N]
#     x2 = [line.split(' ')[0] for line in lines]
#     y2 = [line.split(' ')[1] for line in lines]

# x=np.array(x,float)
# y=np.array(y,float)
# #y=y[:]+random()

# print(y)
# print("")

# xmax1=x.max()
# xmin1=x.min()
# xmax2, xmin2 = y.max(), y.min()
# umax=(xmax1+xmax2)/2
# umin=(xmin1+xmin2)/2

# x1 = (x - xmin1)/(xmax1 - xmin1)
# y1 = (y - xmin2)/(xmax2 - xmin2)

# #print(t.shape)
# plt.figure(1)

# plt.figure(1)
# plt.subplot(211)
# plt.plot(x, y, 'b')

# plt.subplot(212)
# plt.plot(x2, y2, 'r--')
# #ax = fig.add_subplot(111, aspect='equal', autoscale_on=False,
#                      #xlim=(-1, 1), ylim=(-1, 1))
# #ax1.set_title("Plot title")    
# #ax1.set_xlabel('x label')
# #ax1.set_ylabel('y label')

# #ax1.plot(t,x, c='r', label='the data')
# #ax2.plot(x,y, c='b', label='the data')


# #leg = ax1.legend()

# plt.show()


Q_raw = np.loadtxt('trajectoire_cercle_angle.txt', dtype=float)

print ('raw angle data size',np.shape(Q_raw)) #175536
#print('raw angle data :',b)
print("\n")

#ange en degres + chaque ligne a 6 compos
for ii in range(0,29256):
 #Q_raw[ii][5]=1	# Voir le dernier angle!! sup a 360
 print str([Q_raw[ii][i]*180./pi for i in xrange(0,6)])

 

t = np.loadtxt('trajectoire_cercle_time.txt', dtype=float)

print ('raw angle data size',np.shape(t))  #4876
#print('raw angle data :',b)
print("\n")

#print(b[:,2]) #all rows third collum
#a=b[::+36] #all rows every 175536/4876=+36 collum

#print ('a =', a)
#print np.shape(a)
print("\n")

#g=a[1:][:]
#print ('g=',g)

#Eviter les Limites :
# for ii in range(0,29256):
#  for jj in range(0,6) :
#   Q_raw[ii][jj]=Q_raw[ii][jj]+0.17
#  #Q[ii][5]=1
#  if Q_raw[ii][0] >= 3.1:
#     Q_raw[ii][0]=Q_raw[ii-1][0]	
#  if Q_raw[ii][0] <= -3.1:
#     Q_raw[ii][0]=Q_raw[ii-1][0]	
 
#  if Q_raw[ii][5] >= 3.1:
#     Q_raw[ii][5]=Q_raw[ii][5]-14.5	
#  if Q_raw[ii][5] <= -3.1:
#     Q_raw[ii][5]=Q_raw[ii][5]+14.5   
    
 
#Get every angle
Q1=np.copy(Q_raw[:,0])
Q2=np.copy(Q_raw[:,1])
Q3=np.copy(Q_raw[:,2])
Q4=np.copy(Q_raw[:,3])
Q5=np.copy(Q_raw[:,4])
Q6=np.copy(Q_raw[:,5])
#np.sizeof
#q1=np.copy(b[:][])

c1=np.copy(Q1[::+6])+random()
c2=np.copy(Q2[::+6])+random()
c3=np.copy(Q3[::+6])+random()
c4=np.copy(Q4[::+6])+random()
c5=np.copy(Q5[::+6])+random()
c6=np.copy(Q6[::+6])+random()

#not getting oveer limits:
for ii in range(0,29256):
 if Q1[ii] >= 3.1:
    Q1[ii]=Q1[ii-1]	
 if Q1[ii] <= -3.1:
    Q1[ii]=Q1[ii-1]	
 if Q6[ii] >= 3.1:
    Q6[ii]=Q6[ii]-14.5	
 if Q6[ii] <= -3.1:
    Q6[ii]=Q6[ii]+14.5   

#print('extract data',Q1)
print('size extract data', np.shape(Q1))
a1=Q1[::+6]
a2=Q2[::+6]
a3=Q3[::+6]
a4=Q4[::+6]
a5=Q5[::+6]
a6=Q6[::+6]
print('size extract data', np.shape(a1))

# read angle velcity :

dQ_raw = np.loadtxt('trajectoire_cercle_velocity.txt', dtype=float)

print ('raw velocity data size',np.shape(dQ_raw))  #4876

dQ1=np.copy(dQ_raw[:,0])
dQ2=np.copy(dQ_raw[:,1])
dQ3=np.copy(dQ_raw[:,2])
dQ4=np.copy(dQ_raw[:,3])
dQ5=np.copy(dQ_raw[:,4])
dQ6=np.copy(dQ_raw[:,5])


b1=dQ1[::+6]
b2=dQ2[::+6]
b3=dQ3[::+6]
b4=dQ4[::+6]
b5=dQ5[::+6]
b6=dQ6[::+6]

print('/n')

# SAME=0
# for ii in range(0,29256):
#  for jj in range(0,6):
#   a=Q_raw[ii][jj]
#   b=dQ_raw[ii][jj]
#  if a == b :
#    SAME=SAME+1
#    print a,b


#Calculate the q=dq*t
Q_estim1=np.multiply(b1,t)
Q_estim2=np.multiply(b2,t)
Q_estim3=np.multiply(b3,t)
Q_estim4=np.multiply(b4,t)
Q_estim5=np.multiply(b5,t)
Q_estim6=np.multiply(b6,t)


#--------------------------------------------plotting--------------------------------------------------------------------

fig=plt.figure(1)
ax=fig.gca()
plt.plot(t, a1, 'b--',label="Angle n1")
plt.plot(t, a2, 'g--',label="Angle n2")
plt.plot(t, a3, 'r--',label="Angle n3")
plt.plot(t, a4, 'c--',label="Angle n4")
plt.plot(t, a5, 'y--',label="Angle n5")
plt.plot(t, a6, 'm--',label="Angle n6")
#ax.set_xlim([])
#ax.set_ylim([-3.14,3.14])
#ax.legend()
ax.set_ylabel('Joint Angles (rad)')
ax.set_xlabel('time step dt=.0018ms')
ax.set_title('Joints Angles varriation for a circular path simlation')
plt.legend()
plt.grid()

fig4=plt.figure(4)
ax4=fig4.gca()
plt.plot(t, c1, 'b--',label="Angle n1")
plt.plot(t, c2, 'g--',label="Angle n2")
plt.plot(t, c3, 'r--',label="Angle n3")
plt.plot(t, c4, 'c--',label="Angle n4")
plt.plot(t, c5, 'y--',label="Angle n5")
plt.plot(t, c6, 'm--',label="Angle n6")
#ax.set_xlim([])
#ax.set_ylim([-3.14,3.14])
#ax.legend()
ax4.set_ylabel('Joints Angles (rad)')
ax4.set_xlabel('time step dt=.0018ms')
ax4.set_title('Joints Angles varriation for a circular path real')
plt.legend()
plt.grid()

# # plot the estimed angles
# fig2=plt.figure(2)
# ax1=fig2.gca()
# plt.plot(t, Q_estim1, 'b--',label="Angle n1")
# plt.plot(t, Q_estim2, 'g--',label="Angle n2")
# plt.plot(t, Q_estim3, 'r--',label="Angle n3")
# plt.plot(t, Q_estim4, 'c--',label="Angle n4")
# plt.plot(t, Q_estim5, 'y--',label="Angle n5")
# plt.plot(t, Q_estim6, 'm--',label="Angle n6")
# ax1.set_ylabel('Joints Angles (rad)')
# ax1.set_xlabel('time step dt=.0018ms')
# ax1.set_title('Joints estimed Angles varriation for a circular path')
# plt.legend()
# plt.grid()

# #plot the velocity
# fig3=plt.figure(3)
# ax2=fig3.gca()
# plt.plot(t, b1, 'b--',label="Angle n1")
# plt.plot(t, b2, 'g--',label="Angle n2")
# plt.plot(t, b3, 'r--',label="Angle n3")
# plt.plot(t, b4, 'c--',label="Angle n4")
# plt.plot(t, b5, 'y--',label="Angle n5")
# plt.plot(t, b6, 'm--',label="Angle n-")
# ax2.set_ylabel('Joints Angles (rad)')
# ax2.set_xlabel('time step dt=.0018ms')
# ax2.set_title('Joints Velocity varriation for a circular path')
# plt.legend()
# plt.grid()





plt.show()
