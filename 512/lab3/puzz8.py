#Jerome Hayes Jr
#puzz8.py

import copy #allows you to make copies

mypuzz = {(1,1):1, (1,2):3, (1,3):5, \
          (2,1):8, (2,2):7, (2,3):"B", \
          (3,1):4, (3,2):6, (3,3):2}

GOAL = {(1,1):1, (1,2):2, (1,3):3, \
          (2,1):4, (2,2):5, (2,3):6,\
          (3,1):7, (3,2):8, (3,3):"B"}

def show_puzz(x):
    for i in range(3):
        for j in range(3):
            print "%s" % x[(i+1,j+1)],
        print " "
    return

#checks puzzle to see how different is to the goal
#returns the number of tiles out of place
def eval_fct(x):
    count = 0
    for k in x.keys():
        if x[k] != GOAL[k]:
            count += 1
    return count

#Returns list of immediate next puzzle states that
#can be reached via one move of the blank in state.
def successor_fct(x):
    succs = []
    blank = find_blank(x) # coordinates (r,c) of blank in state x
    if blank[0] > 1:
        succs.append(move_blank_up(x))
    if blank[0] < 3:
        succs.append(move_blank_down(x))
    if blank[1] > 1:
        succs.append(move_blank_left(x))
    if blank[1] < 3:
        succs.append(move_blank_right(x))
    return succs
    

#locate and return blank coordinates
def find_blank(x):
    for blank in x:
        if(x[blank] == "B"):
            return blank


def move_blank_up(x):
    cpx = copy.deepcopy(x)
    blank = find_blank(cpx)
    abovex = blank[0] - 1
    abovey = blank[1]
    temp = cpx[blank]
    cpx[blank] = cpx[abovex,abovey]
    cpx[abovex,abovey] = temp
    return cpx

def move_blank_down(x):
    cpx = copy.deepcopy(x)
    blank = find_blank(cpx)
    bottomx = blank[0] + 1
    bottomy = blank[1]
    temp = cpx[blank]
    cpx[blank] = cpx[bottomx, bottomy]
    cpx[bottomx,bottomy] = temp
    return cpx

def move_blank_left(x):
    cpx = copy.deepcopy(x)
    blank = find_blank(cpx)
    leftx = blank[0]
    lefty = blank[1] - 1
    temp = cpx[blank]
    cpx[blank] = cpx[leftx, lefty]
    cpx[leftx,lefty] = temp
    return cpx

def move_blank_right(x):
    cpx = copy.deepcopy(x)
    blank = find_blank(cpx)
    rightx= blank[0]
    righty= blank[1] + 1
    temp = cpx[blank]
    cpx[blank] = cpx[rightx,righty]
    cpx[rightx,righty] = temp
    return cpx

def goal_fct(x):
    if x == GOAL:
        return True
    else:
        return False
