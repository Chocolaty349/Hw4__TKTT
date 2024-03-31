import numpy as np
import sys

# matrix size
n = int(sys.argv[1])

def generate_symmetric_matrix(n):
    # Generate a random square matrix of size n x n
    random_matrix = np.random.randint(1, 100, size=(n, n))
    
    # Make the matrix symmetric
    symmetric_matrix = random_matrix + random_matrix.T - np.diag(random_matrix.diagonal())
    
    for i in range(n):
        symmetric_matrix[i][i] = 0

    return symmetric_matrix


# Generate a random symmetric integer matrix of size n x n
symmetric_matrix = generate_symmetric_matrix(n)

print("Random Symmetric Integer Matrix:")
print(symmetric_matrix)
