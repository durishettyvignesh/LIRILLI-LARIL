import numpy as np

arr = np.array([[1, 2, 3], [4, 5, 6]], dtype=np.int32)
print(arr)
print(arr.shape)
print(arr.dtype)
print(arr.ndim)
print(arr.size)
print(arr.nbytes)
print(arr.itemsize)
print(arr.data)
print(arr.strides)
print(arr.T)
print(arr.flatten())
print(arr.ravel())
print(arr.reshape(3, 2))
print(arr.astype(np.float64))
print(arr.tolist())
print(arr.sum())



# Example of stacking arrays
a = np.array([1, 2, 3])
b = np.array([4, 5, 6])
print(np.vstack((a, b)))
print(np.hstack((a, b)))
print(np.column_stack((a, b)))
print(np.row_stack((a, b)))
print(np.dstack((a, b)))
print(np.concatenate((a, b)))
print(np.stack((a, b)))
print(np.block([[a], [b]]))
