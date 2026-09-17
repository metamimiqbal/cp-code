import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.tsa.stattools import adfuller
data = [963, 1119, 1074, 1169, 1143, 1232, 1128, 1133, 1098, 1237,
        1333, 1260, 1289, 1262, 1407, 1584, 1490, 1623, 1590, 1615,
        1668, 1900, 1850, 1983, 1916, 1842, 1895, 1947, 1714, 1880]
s = pd.Series(data, index=pd.RangeIndex(1, 31, name="Day"))
ma7 = s.rolling(window=7).mean()
result = adfuller(s)

print(f"ADF Statistic: {result[0]:.4f}")
print(f"p-value: {result[1]:.4f}")
print("Stationary" if result[1] < 0.05 else "Non-stationary")
fig, ax = plt.subplots(figsize=(10, 5.5))
ax.plot(s.index, s.values, marker='o', markersize=4, linewidth=1.5,
        color='#4C72B0', label='Daily traffic')
ax.plot(ma7.index, ma7.values, linewidth=2.5,
        color='#DD8452', label='7-day moving average')
ax.set_title('Daily Website Traffic (30 Days) with 7-Day Moving Average')
ax.set_xlabel('Day')
ax.set_ylabel('Visits')
ax.legend()
ax.grid(alpha=0.3)
plt.tight_layout()
plt.savefig('traffic_analysis.png', dpi=150)