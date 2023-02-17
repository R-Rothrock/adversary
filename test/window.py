#!/usr/bin/python3
# window.py
# no dependencies but the standard library.

import ctypes
import tkinter as tk

ROCK     = 1
PAPER    = 2
SCISSORS = 3
OPTIONS  = (ROCK, PAPER, SCISSORS)

player_guess = 0 # for now...

# loading shared object library
# make sure .so of adversary is compiled and inside this directory

dll = ctypes.cdll.LoadLibrary("./adversary.so")

def adversary(player_guess: int) -> int:
    """
    RETURNS
    ---
    - 1: computer wins ):
    - 2: you win (:
    - 3: tie ~}:
    """
    assert player_guess in OPTIONS
    return dll.adversary_round(player_guess)

def guess_rock(player_guess=player_guess) -> None:
    player_guess = ROCK
    print("[+] player guess is rock")

def guess_paper(player_guess=player_guess) -> None:
    player_guess = PAPER
    print("[+] player guess is paper")

def guess_scissors(player_guess=player_guess) -> None:
    player_guess = SCISSORS
    print("[+] player guess is scissors")

# now the GUI, courtesy of tkinter from the STL

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
).grid(row=4, column=1, stick=tk.W)

win.mainloop()

print(player_guess)
