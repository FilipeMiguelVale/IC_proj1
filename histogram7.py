import matplotlib.pyplot as plt
import numpy as np
import sys
# An "interface" to matplotlib.axes.Axes.hist() method
a = []
r = []
g = []
b = []
d = []
for i in range(0,256):
	a.append(i)

f = open(sys.argv[1], "r")
for x in f:
  values = x.split("\t")
  r.append(values[0])
  g.append(values[1])
  b.append(values[2])

d.append(r)
d.append(g)
d.append(b)


X = np.arange(256)

fig = plt.figure()
plt.subplot(212)
plt.bar(X, d[0], color = 'r')
plt.xlim([0,256])
plt.yscale('linear')
plt.grid(True)


plt.subplot(221)
plt.bar(X, d[1], color = 'g')
plt.yscale('linear')
plt.xlim([0,256])
plt.grid(True)


plt.subplot(222)
plt.bar(X, d[2], color = 'b')
plt.yscale('linear')
plt.xlim([0,256])
plt.grid(True)

plt.show()