#!/usr/bin/env python
# coding: utf-8

# # STATISTICAL ANALYSIS

# In[1]:


# importing libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import copy
get_ipython().run_line_magic('matplotlib', 'inline')


# In[2]:


gt = pd.read_csv('GlobalTemperatures.csv')
gt.dropna(inplace = True)
gt.head()


# In[3]:


print(gt.isnull().sum())


# In[4]:


gt.info()


# In[5]:


columns = gt.columns
columns


# ## COVARIANCE

# In[6]:


def covariance(a, b):
    if len(a) != len(b):
        return

    a_mean = np.mean(a)
    b_mean = np.mean(b)

    sum = 0
    for i in range(0, len(a)):
        sum += ((a[i] - a_mean) * (b[i] - b_mean))

    return sum/(len(a)-1)


# In[7]:


# this covariance is calculated without scaling the dataset
# but nan values have been dropped

cov_gt = np.zeros((8, 8), dtype = float)
x = 0
arr = np.array(gt[columns[1:]]).transpose()
# print(len(arr[0]))
for col1 in arr:
    y = 0
    for col2 in arr:
        cov_gt[x][y] = covariance(col1, col2)
        y += 1
    x += 1
    
print(cov_gt) # == np.cov(arr))
print("\n")
print(np.cov(arr))


# In[8]:


fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])
sns.heatmap(pd.DataFrame(cov_gt), annot=True)
fig.savefig('covariance_heatmap_scratch.png', bbox_inches = 'tight')


# ## CORRELATION

# In[13]:


def correlation(a, b):
    c = covariance(a, b)
    std_a = np.std(a)
    std_b = np.std(b)
    corrn = c/(std_a * std_b)
    return corrn


# In[16]:


corr_gt = np.zeros((8, 8), dtype = float)
x = 0
arr = np.array(gt[columns[1:]]).transpose()
# print(len(arr[0]))
for col1 in arr:
    y = 0
    for col2 in arr:
        corr_gt[x][y] = correlation(col1, col2)
        y += 1
    x += 1
    
print(corr_gt) # == np.cov(arr))
print("\n")
print(np.array(gt[columns[1:]].corr()))


# In[17]:


fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])
sns.heatmap(pd.DataFrame(corr_gt), annot=True)
fig.savefig('correlation_heatmap_scratch.png', bbox_inches = 'tight')


# ## PCA

# In[9]:


from sklearn.preprocessing import StandardScaler
gt_sdt = StandardScaler().fit_transform(gt[columns[1:]])
gt_scaled = pd.DataFrame(StandardScaler().fit_transform(gt[columns[1:]]))
gt_scaled


# In[10]:


gt_arr = np.array(gt[columns[1:]])
mean = np.mean(gt_arr, axis=0)
mean
#nan values are ignored with sklearn so we can do the same


# In[11]:


features = gt_sdt.T
cov_matrix = np.cov(features)
c = pd.DataFrame(cov_matrix)

fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])
sns.heatmap(c, annot=True)
fig.savefig('covariance_heatmap.png', bbox_inches = 'tight')


# In[12]:


values, vectors = np.linalg.eig(cov_matrix)
print(values)
print("\n")
print(vectors)


# In[19]:


max_abs_idx = np.argmax(np.abs(vectors), axis=0)
# print(max_abs_idx)
signs = np.sign(vectors[max_abs_idx, range(vectors.shape[0])])
# print(signs)
vectors = vectors*signs[np.newaxis,:]
# print(vectors)
vectors = vectors.T
print(vectors)


# In[21]:


explained_variances = []
for i in range(len(values)):
    explained_variances.append(values[i] / np.sum(values))
 
print(np.sum(explained_variances), "\n", explained_variances)


# In[26]:


projected_1 = gt_scaled.dot(vectors.T[0])
projected_2 = gt_scaled.dot(vectors.T[1])
res = pd.DataFrame(projected_1, columns=["PC1"])
res["PC2"] = projected_2
res["Date"] = gt['dt']
res.head()


# In[35]:


fig = plt.figure(figsize=(20, 10))
axes = fig.add_axes([0, 0, 1, 1])
sns.scatterplot(res['PC1'], res['PC2'], ax = axes)
fig.savefig('PCA_plot.png', bbox_inches = 'tight')


# ## LINEAR DISCRIMINANT ANALYSIS

# In[36]:


from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris


# In[37]:


data = load_iris()
X, y = data.data, data.target
X_train, X_test, Y_train, Y_test = train_test_split(X, y, test_size=0.2)


# In[41]:


height, width = X_train.shape
unique_classes = np.unique(Y_train)
num_classes = len(unique_classes)

scatter_t = np.cov(X_train.T)*(height - 1)
scatter_w = 0
for i in range(num_classes):
    class_items = np.flatnonzero(Y_train == unique_classes[i])
    scatter_w = scatter_w + np.cov(X_train[class_items].T) * (len(class_items)-1)
        
scatter_b = scatter_t - scatter_w
_, eig_vectors = np.linalg.eigh(np.linalg.pinv(scatter_w).dot(scatter_b))
print(eig_vectors.shape)
pc = X.dot(eig_vectors[:,::-1][:,:3])
print(pc.shape)


# In[42]:


colors = ['r','g','b']
labels = np.unique(y)
for color, label in zip(colors, labels):
    class_data = pc[np.flatnonzero(y==label)]
    plt.scatter(class_data[:,0],class_data[:,1],c=color)


# ## MULTIVARIATE LINEAR REGRESSION

# In[45]:


features = gt_sdt.T
cov_matrix = np.cov(features)
c = pd.DataFrame(cov_matrix)
c.columns = columns[1:]
c


# In[51]:


#How does landmaxtemtperature, landmintemperature, LandAndOceanAverageTemperature affect landAaveragetemperature?
#Multivariate linear regression

mlr = pd.DataFrame(gt[columns[1:9:2]])
mlrcolumns = mlr.columns
mlr


# In[52]:


mlrcolumns


# In[59]:


X = mlr[mlrcolumns[1:]]
Y = mlr[mlrcolumns[0]]


# In[61]:


from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X = sc.fit_transform(X)
X


# In[63]:


def cost_function(X, Y, B):
    m = len(Y)
    J = np.sum((X.dot(B) - Y) ** 2)/(2 * m)
    return J


# In[67]:


def batch_gradient_descent(X, Y, B, alpha, iterations):
    cost_history = [0] * iterations
    m = len(Y)

    for iteration in range(iterations):
         #print(iteration)
         # Hypothesis Values
        h = X.dot(B)
         # Difference b/w Hypothesis and Actual Y
        loss = h - Y
         # Gradient Calculation
        gradient = X.T.dot(loss) / m
         # Changing Values of B using Gradient
        B = B - alpha * gradient
         # New Cost Value
        cost = cost_function(X, Y, B)
        cost_history[iteration] = cost

    return B, cost_history


# In[103]:


m = 1500
f = 3
X_train = X[:m,:f]
X_train = np.c_[np.ones(len(X_train),dtype='int64'),X_train]
y_train = y[:m]
X_test = X[m:,:f]
X_test = np.c_[np.ones(len(X_test),dtype='int64'),X_test]
y_test = y[m:]
# X_train


# In[104]:


# Initial Coefficients
B = np.zeros(X_train.shape[1])
alpha = 0.005
iter_ = 2000
newB, cost_history = batch_gradient_descent(X_train, y_train, B, alpha, iter_)


# In[105]:


# y_ = pred(X_test,newB)
y_ = (X_test)*(newB)
y_


# In[106]:


y_ = np.sum(y_, axis = 1)


# In[107]:


def r2(y_,y):
    sst = np.sum((y-y.mean())**2)
    ssr = np.sum((y_-y)**2)
    r2 = 1-(ssr/sst)
    return(r2)


# In[102]:


r2(y_, y_test) #99% accuracy is pretty good


# In[ ]:




