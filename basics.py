from flask import Flask, render_template

#return the name of python script
app=Flask (__name__)

#type Home in link to view page
@app.route('/frontend')
def home():
    #access html file using this line
    return render_template("frontend.html")

#if we are current python scriot return name
if __name__ == "__main__":
    app.run(debug=True)  # debug -> no need to re run python script again and agian

