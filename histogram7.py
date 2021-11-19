import matplotlib.pyplot as plt
import numpy as np
import sys
# An "interface" to matplotlib.axes.Axes.hist() method
gr = []
r = []
g = []
b = []
d = []


f = open(sys.argv[1], "r")
for x in f:
  values = x.split("\t")
  r.append(values[0])
  g.append(values[1])
  b.append(values[2])
  gr.append(values[3])

d.append(r)
d.append(g)
d.append(b)
d.append(gr)


X = np.arange(256)

fig = plt.figure()
plt.subplot(221)
plt.bar(X, d[0], color = 'r')
plt.xlim([0,256])
plt.yscale('linear')
plt.grid(True)


plt.subplot(222)
plt.bar(X, d[1], color = 'g')
plt.yscale('linear')
plt.xlim([0,256])
plt.grid(True)


plt.subplot(223)
plt.bar(X, d[2], color = 'b')
plt.yscale('linear')
plt.xlim([0,256])
plt.grid(True)

plt.subplot(224)
plt.bar(X, d[3], color = 'black')
plt.yscale('linear')
plt.xlim([0,256])
plt.grid(True)

plt.show()