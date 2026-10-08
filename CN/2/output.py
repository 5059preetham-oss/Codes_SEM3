import matplotlib.pyplot as plt

# Your recorded data
connections = [0, 2, 4, 6, 8, 10]
load_times = [1.1473, 1.3633, 1.2686, 1.1553, 1.0572, 0.6951]

# Create the plot
plt.figure(figsize=(8, 5))
plt.plot(connections, load_times, marker='o', linestyle='-', color='b')

# Add labels and title exactly as required
plt.title('Total Page Load Time vs. Number of Persistent Connections')
plt.xlabel('Number of Persistent Connections')
plt.ylabel('Total Page Load Time (seconds)')

# Add grid for readability
plt.grid(True)
plt.xticks(connections)

# Save the graph as an image file for your submission
plt.savefig('load_time_graph.png')
plt.show()
