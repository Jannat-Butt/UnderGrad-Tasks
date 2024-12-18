import numpy as np
from collections import Counter

class knn:
    def __init__(self, X_train,X_test, y_train, y_test, k):
        self.X_train=X_train
        self.X_test=X_test
        self.y_train=y_train
        self.y_test=y_test
        self.k =k

    #def display(self, pred):
        # Convert y_test to a list for comparison
     #   y = self.y_test.tolist()
      #  accuracy = accuracy_score(y, pred)
       # print(f'Accuracy: {accuracy:.2f}')

    def find_k(self, dist, labels):
        # Sort distances and corresponding labels
        sorted_data =sorted(zip(dist, labels))
        k_values =sorted_data[:self.k]
        k_labels =[label for _, label in k_values]
        counts =Counter(k_labels)
        common_label =counts.most_common(1)[0][0]
        return common_label

    def main_loop(self):
        pred = []
        for i in self.X_test:
            distances= []
            labels= []
            for index, j in enumerate(self.X_train):
                dist= np.sqrt(np.sum((i - j) ** 2))
                distances.append(dist)
                #use numpy indexing
                labels.append(self.y_train[index])  
            pred.append(self.find_k(distances, labels))
        #self.display(pred)
