import numpy as np

# def compute_model_output(x, w, b):
#     """
#     Computes the prediction of a linear model
#     Args:
#       x (ndarray (m,)): Data, m examples 
#       w,b (scalar)    : model parameters  
#     Returns
#       f_wb (ndarray (m,)): model prediction
#     """
#     m = x.shape[0]
#     f_wb = np.zeros(m)
#     for i in range(m):
#         f_wb[i] = w * x[i] + b
        
#     return f_wb

print(np.zeros(4))

x = np.array([
    [10, 20],
    [30, 40],
    [50, 60]
])

print(x.shape)     # (3, 2)
print(x.shape[0])  # 3 rows
print(x.shape[1])  # 2 columns
print(len(x))      # 3 — same as x.shape[0]