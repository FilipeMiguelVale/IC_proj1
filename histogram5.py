import matplotlib.pyplot as plt
import numpy as np
import sys

y_axis = []
x_axis = []


f = open(sys.argv[1], "r")
for i,x in enumerate(f):
  if int(x) != 0 :
  	print("hello "+ str(i))
  	x_axis.append(chr(int(i)))
  	y_axis.append(int(x))
  	

print(x_axis)
print(y_axis)

fig = plt.figure()
ax = fig.add_axes([0.1,0.1,0.9,0.9])

ax.bar(x_axis,y_axis)
plt.show()


plt.show()