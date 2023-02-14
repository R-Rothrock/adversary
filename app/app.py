#!/usr/bin/python3
"""
Flask web interface for _Adversary_
https://github.com/R-Rothrock/adversary
MIT License
see _LICENSE_ for more details.
"""

import ctypes
from flask import Flask, render_template, request

dll = ctypes.LibraryLoader("./adversary.so")

ROCK = "rock"
PAPER = "paper"
SCISSORS = "scissors"
USER_GUESS = str()

app = Flask(__name__)

@app.route('/', methods=["POST", "GET"])
def index():
    """
    /index
    """
    if request.method == 'POST':
        print(request.form['rock'])
    return render_template('./index.html', user_guess=USER_GUESS)
