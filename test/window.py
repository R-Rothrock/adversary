#!/usr/bin/python3
# window.py
# no dependencies but the standard library.

from ctypes import CDLL
import tkinter

try:
    dll = CDLL("./adversary.so")
except FileNotFoundError:
    print("'adversary.so' not found. Compiling now.")
    import os
    try:
        os.system("source compile_dll")
    except:
        raise RuntimeError(
            "compilation failed. https://github.com/R-Rothrock/adversary for more information"
        )

print(dll.play_round(2))
