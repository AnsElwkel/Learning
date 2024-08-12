import numpy as np
import math, copy
import matplotlib.pyplot as plt
# plt.style.use('./deeplearning.mplstyle')

def model_prediction(x, w, b): #single predict
    f_wb = np.dot(x, w) + b
    print(f_wb)
    return f_wb

def compute_cost(X , y , W , b):
    m = len(y)
    cost = 0.0
    for i in range(m):
        f_wb = np.dot(X[i], W) + b
        cost += (f_wb - y[i])**2
    j_wb = (1 / (2*m)) * cost
    return j_wb

def compute_derivative(X , y , w, b): #Calculate partial derivative
    m,n = X.shape
    dj_dw = np.zeros((n,))
    dj_db = 0
    for i in range(m):
        err = (np.dot(X[i], w) + b) - y[i]
        for j in range(n):
            dj_dw += err * X[i,j]
        dj_db += err
    dj_db /= m
    dj_dw /= m
    return dj_db, dj_dw

def compute_gradient(X , y , w_in , b_in , alpha , num_iters):
    w = copy.deepcopy(w_in)
    b = b_in
    for i in range(num_iters):
        tmp_db , tmp_dw = compute_derivative(X , y  , w, b)
        w = w - alpha * tmp_dw
        b = b - alpha * tmp_db
    return w , b




x_train = np.array([[2104, 5, 1, 45],
                    [1416, 3, 2, 40],
                    [852, 2, 1, 35]])

y_train = np.array([460, 232, 178])

b_init = 785.1811367994083
w_init = np.array([ 0.39133535, 18.75376741, -53.36032453, -26.42131618])

initial_w = np.zeros_like(w_init)
initial_b = 0

iteration = 1000
alpha = 5.0e-7

w_final ,b_final = compute_gradient(x_train , y_train ,initial_w , initial_b , alpha , iteration)
print(w_final , b_final)

