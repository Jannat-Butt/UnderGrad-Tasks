from flask import Flask, request, render_template, jsonify
import pickle
import numpy as np

app = Flask(__name__)

# Load the model
with open('regression_model.pkl', 'rb') as f:
    model = pickle.load(f)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/predict', methods=['POST'])
def predict():
    years_of_experience = request.form['YearsExperience']
    features = np.array([[years_of_experience]])
    prediction = model.predict(features)[0]
    return jsonify({'Salary': prediction})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
