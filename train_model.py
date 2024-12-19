# train_model.py
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import pickle

# Read data from CSV file
df = pd.read_csv('salary_data.csv')

# Features and target
X = df[['YearsExperience']]
y = df['Salary']

# Split data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train a simple linear regression model
model = LinearRegression()
model.fit(X_train, y_train)

# Save the trained model as a pickle file
with open('regression_model.pkl', 'wb') as f:
    pickle.dump(model, f)
