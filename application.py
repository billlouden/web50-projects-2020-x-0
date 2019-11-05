import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    # Error conditions
    if not request.form.get("name"):
        return render_template("error.html", message="You must enter a name.")
    elif not request.form.get("party"):
        return render_template("error.html", message="Enter your party affiliation or None.")
    elif not request.form.get("president"):
        return render_template("error.html", message="Please select a candidate.")
    # open file and read in comma delimited variables (columns)
    file = open("survey.csv", "a")
    writer = csv.writer(file)
    writer.writerow((request.form.get("name"), request.form.get("party"), request.form.get("president")))
    file.close()
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    file = open("survey.csv", "r")
    reader = csv.reader(file)
    votes = list(reader)
    return render_template("results.html", votes=votes)

