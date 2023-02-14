#!/usr/bin/python3
"""
Tkinter GUI interface to _Adversary_
https://github.com/R-Rothrock/adversary
MIT License
see _LICENSE_ for more details.
"""

import ctypes
from flask import Flask, render_template

dll = ctypes.LibraryLoader("./adversary.so")

app = Flask(__name__)

@app.route('/')
def index():
    """
    /index.html
    """
    return render_template('index.html')
