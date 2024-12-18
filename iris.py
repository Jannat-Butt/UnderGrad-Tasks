import numpy as np
import pandas as pd
import pickle
from knn_model import knn

#csv read
iris=pd.read_csv("IRIS.csv")

#convert labels to numerical
iris.loc[iris["species"]=='Iris-setosa', 'species'] = 0
iris.loc[iris["species"]=='Iris-virginica', 'species'] = 1
iris.loc[iris["species"]=='Iris-versicolor', 'species'] = 2

#numpy array
X=iris.iloc[:, :-1].values 
y=iris["species"].values  


#custom train test split
def train_test_split(X, y, test_size=0.3, random_state=None):
    if random_state is not None:
        np.random.seed(random_state)
    
    indices=np.arange(X.shape[0])
    np.random.shuffle(indices)
    
    split_index=int(X.shape[0]*(1-test_size))
    
    train_indices=indices[:split_index]
    test_indices=indices[split_index:]
    
    return X[train_indices], X[test_indices], y[train_indices], y[test_indices]
    
#data splitting
X_train, X_test, y_train, y_test=train_test_split(X, y, test_size=0.3, random_state=45)

#print("X_train shape:", X_train.shape)
#print("X_test shape:", X_test.shape)

#make instance and run
knn_obj = knn(X_train, X_test, y_train, y_test, 3)
knn_obj.main_loop()
#save model
with open('iris.pkl', 'wb') as f:
    pickle.dump(knn_obj, f)
