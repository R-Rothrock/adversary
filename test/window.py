#!/usr/bin/python3

import ctypes
import tkinter as tk

ROCK     = 1
PAPER    = 2
SCISSORS = 3
OPTIONS  = (ROCK, PAPER, SCISSORS)

player_guess = 0

# must initialize GUI up here
win = tk.Tk()
win.geometry("300x300")

computer_repr = tk.StringVar()
guess_repr    = tk.StringVar()
res_repr      = tk.StringVar()

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
    match player_guess:
        case 1: # rock
            guess_repr.set("your guess: rock")
        case 2: # paper
            guess_repr.set("your guess: paper")
        case 3: # scissors
            guess_repr.set("your guess: scissors")

    global computer_guess
    computer_guess = dll.adversary_bot()
    match computer_guess:
        case 1: # rock
            computer_repr.set("computer guess: rock")
        case 2: # paper
            computer_repr.set("computer_guess: paper")
        case 3: # scissors
            computer_repr.set("computer_guess: scissors")

    eval_ret = dll.evaluate(player_guess, computer_guess)
    match eval_ret:
        case 1: # computer wins
            res_repr.set("computer wins ):")
        case 2: # player wins
            res_repr.set("you win (:")
        case 3: # tie
            res_repr.set("tie ~}:")

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
).grid(row=5, column=1, pady=10, sticky=tk.W)

# player guess display
tk.Label(
    win,
    textvariable=guess_repr
).grid(row=6, column=1)

# computer guess display
tk.Label(
    win,
    textvariable=computer_repr
).grid(row=7, column=1)

# evaluation display
tk.Label(
    win,
    textvariable=res_repr
).grid(row=8, column=1)

win.mainloop()
