import matplotlib.pyplot as plt
n_values ={10000,20000,30000,40000}
time_taken={0.0000,0.003000,0.004000,0.006000}
plt.plot(n_values,time_taken,marker="o")
plt.title("Quick Sort Time Complexity")
plt.xlabel("Number of Elements(n)")
plt.ylabel("Time Taken (secs)")
plt.grid(True)
plt.show()
