#!/usr/bin/python3

import ctypes
import tkinter as tk

ROCK     = 1
PAPER    = 2
SCISSORS = 3
OPTIONS  = (ROCK, PAPER, SCISSORS)

player_guess = 0

# loading shared object library
# make sure .so of adversary is compiled and inside this directory

dll = ctypes.cdll.LoadLibrary("./adversary.so")

def adversary(player_guess: int) -> int:
    """
    - 1: computer wins ):
    - 2: you win (:
    - 3: tie ~}:
    """
    assert player_guess in OPTIONS
    return dll.adversary_round(player_guess)

# functions for button press

def guess_rock() -> None:
    global player_guess
    player_guess = ROCK
    print("[+] player guess is rock")

def guess_paper() -> None:
    global player_guess
    player_guess = PAPER
    print("[+] player guess is paper")

def guess_scissors() -> None:
    global player_guess
    player_guess = SCISSORS
    print("[+] player guess is scissors")

def eval() -> None:
    global result
    result = adversary(player_guess)

# now the GUI

win = tk.Tk()
win.geometry("300x300")

# title
tk.Label(
    win,
    text="Rock Paper Scissors"
).grid(row=1, column=1)

# button for selecting ROCK
tk.Button(
    win,
    text="Rock",
    command=guess_rock
).grid(row=2, column=1, sticky=tk.W)

# button for selecting PAPER
tk.Button(
    win,
    text="Paper",
    command=guess_paper
).grid(row=3, column=1, sticky=tk.W)

# button for selecting SCISSORS
tk.Button(
    win,
    text="Scissors",
    command=guess_scissors
).grid(row=4, column=1, sticky=tk.W)

# button for sending guess
tk.Button(
    win,
    text="Go",
    command=eval
).grid(row=5, column=1, pady=10, stick=tk.W)

tk.Label(
    win,
    textvariable=
)

win.mainloop()
