# plot
import matplotlib.pyplot as plt
import numpy as np

# Func Case:1
# n = 250,Elapsed time: 0.019741 s
# n = 500,Elapsed time: 0.0955126 s
# n = 1000,Elapsed time: 0.444183 s
# n = 2000,Elapsed time: 1.91578 s


# Func Case:2
# n = 25000,Elapsed time: 0.0853942 s
# n = 50000,Elapsed time: 0.173982 s
# n = 100000,Elapsed time: 0.368948 s
# n = 200000,Elapsed time: 0.908983 s
# n = 400000,Elapsed time: 2.13893 s
# n = 800000,Elapsed time: 4.94547 s


# Func Case:3
# n = 100000,Elapsed time: 0.0377167 s
# n = 200000,Elapsed time: 0.0834251 s
# n = 400000,Elapsed time: 0.18699 s
# n = 800000,Elapsed time: 0.544739 s
# n = 1600000,Elapsed time: 1.01649 s
# n = 3200000,Elapsed time: 3.59457 s


# 绘图, 数据如上

# Func Case:1
x = [250, 500, 1000, 2000]
y = [0.019741, 0.0955126, 0.444183, 1.91578]
plt.scatter(x, y, color='red', linewidths=1.0, linestyle='-')
plt.title('Func Case:1')
plt.xlabel('n')
plt.ylabel('Elapsed time')
plt.show()

# Func Case:2
x = [25000, 50000, 100000, 200000, 400000, 800000]
y = [0.0853942, 0.173982, 0.368948, 0.908983, 2.13893, 4.94547]
plt.scatter(x, y, color='red', linewidths=1.0, linestyle='-')
plt.title('Func Case:2')
plt.xlabel('n')
plt.ylabel('Elapsed time')
plt.show()

# Func Case:3
x = [100000, 200000, 400000, 800000, 1600000, 3200000]
y = [0.0377167, 0.0834251, 0.18699, 0.544739, 1.01649, 3.59457]
plt.scatter(x, y, color='red', linewidths=1.0, linestyle='-')
plt.title('Func Case:3')
plt.xlabel('n')
plt.ylabel('Elapsed time')
plt.show()






