import matplotlib.pyplot as plt 
n_values=[6000,12000,78000,84550]
time_taken=[0.46000,0.187000,7.787000,9.205000]
plt.plot(n_values,time_taken,marker='o')
plt.title("Selection Sort Time Complexity")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()
