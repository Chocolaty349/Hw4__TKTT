import numpy as np
import sys

# Define the size of the square matrix
n = int(sys.argv[1])

# Generate a random square matrix of size n x n
random_matrix = np.random.randint(1, 100, size=(n,n))

print("Random Square Matrix:")
print(random_matrix)
