from flask import Flask, render_template, request, redirect, url_for
import pickle
import numpy as np
from knn_model import knn

#load model
with open('iris.pkl', 'rb') as f:
    model = pickle.load(f)

app = Flask(__name__)
@app.route('/')
def root_redirect():
    #redirect to \frontend
    return redirect(url_for('home'))

@app.route('/frontend')
def home():
    return render_template("frontend.html")

@app.route("/predict", methods=['POST'])
def predict():
    try:
        data1=float(request.form['feature1'])
        data2=float(request.form['feature2'])
        data3=float(request.form['feature3'])
        data4=float(request.form['feature4'])
        arr=np.array([[data1, data2, data3, data4]])
        dist=np.sqrt(np.sum((arr - model.X_train) ** 2, axis=1))
        pred=model.find_k(dist, model.y_train)
        return render_template("after.html", data=pred)
    except Exception as e:
        return str(e)

if __name__ == "__main__":
    app.run(debug=True)
