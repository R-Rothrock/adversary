#!/usr/bin/python3
# window.py
# no dependencies but the standard library.

import ctypes
import tkinter

dll = ctypes.cdll.LoadLibrary("./adversary.so")
print(dll.adversary_round(1))
