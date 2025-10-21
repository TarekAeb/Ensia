# save as plot_ping_ratio.py and run locally (needs matplotlib)
import math
import matplotlib.pyplot as plt

# theoretical data (from earlier computation)
destinations = ['Doha (QU)', 'South Bend (ND)', 'London (Imperial)']
dist_km = [4745.65, 7340.75, 1665.69]          # great-circle distances
T_ms = [15.819, 24.469, 5.552]                # one-way min propagation times in ms
min_RTT_ms = [2*t for t in T_ms]              # absolute min RTT (2*T)

# ---- Replace these measured RTTs with actual ping results (avg RTT in ms) ----
# Example/hypothetical numbers shown below; replace with your measured averages:
measured_RTT_ms = [80.0, 180.0, 40.0]   # <-- **REPLACE** with values from ping

# compute ratio = measured_RTT / (2*T)
ratios = [measured_RTT_ms[i] / min_RTT_ms[i] for i in range(len(T_ms))]

# print table
print("Dest\tDist_km\tT_ms\tmin_RTT_ms\tmeas_RTT_ms\tratio")
for i in range(len(destinations)):
    print(f"{destinations[i]}\t{dist_km[i]:.2f}\t{T_ms[i]:.3f}\t{min_RTT_ms[i]:.3f}\t{measured_RTT_ms[i]:.2f}\t{ratios[i]:.2f}")

# plot
plt.figure(figsize=(8,5))
plt.scatter(dist_km, ratios)
for i,(x,y) in enumerate(zip(dist_km,ratios)):
    plt.text(x, y, f" {destinations[i]} ({y:.2f})", va='bottom')
plt.xlabel('Distance (km)')
plt.ylabel('Ratio = measured RTT / (2·T)')
plt.title('Distance vs RTT/(2·T)')
plt.grid(True)
plt.ylim(0, max(ratios)*1.6)
plt.show()
