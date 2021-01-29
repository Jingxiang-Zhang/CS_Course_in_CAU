import numpy as np
import pandas as pd
import matplotlib.pyplot as plt



def normfun(x,mu, sigma):
    pdf = np.exp(-((x - mu)**2) / (2* sigma**2)) / (sigma * np.sqrt(2*np.pi))
    return pdf

x = np.linspace(0,20,50)
# x数对应的概率密度
y = normfun(x, 10, 3.0)
# rou=1.3，为90%

# 参数,颜色，线宽
plt.plot(x,y, color='g',linewidth = 1)

ytic = np.linspace(0,0.2,5)
plt.yticks(ticks=ytic, rotation=0, fontsize=12, horizontalalignment='center', alpha=.7)

plt.show()

