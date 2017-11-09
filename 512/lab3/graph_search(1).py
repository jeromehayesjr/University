# graph_search.py
# Kerstin Voigt, Jan 2017, after Nils Nilsson's Graph Search Algorithm

# to be used in Lab3;

import random
from puzz8 import *

# node of a directed graph

class Node:
    def __init__(self, num = None, parnum=None, thestate=None, dep=0, val=None):
        self.no = num # a unique state number
        self.parno = parnum # state number of parent node
        self.state = thestate # the actual state
        self.depth = dep # depht of node in search
        self.eval = val # eval fct value 

    def __eq__(self,other):
        return self.state == other.state

# x a "state", nodes a list of elements of type Node
def on_list_of_Nodes(x,lst):
    for y in lst:
        if x == y.state:
            return True
    return False

def on_OPEN(x,op):
    return on_list_of_Nodes(x,op)
    

def on_CLOSED(x,cl):
    return on_list_of_Nodes(x,cl)
    

NUM = 1

# search to GOAL from state start

# the following domain/problem dependent functions will need to be
# provided (here: imported from puzz8.py):
#
# goal_fct(x): True for state x that is 8-puzzle solution
# successor_fct(x): list of immediate successor states of state x
# eval_fct(x): evaluation function to rate state x; example: #tiles out of place;


def graphsearch(start):
    global NUM
    start_node = Node(NUM,None,start,0,None) # casting start "node"
    NUM += 1
    # OPEN: a list of all (partial) paths seen until now
    # initial to path to starting point, [x] 
    OPEN = [start_node]
    CLOSED = []
    k = 1
    while OPEN != []:
        if k > 10000:
            break
        curr = OPEN[0]
        OPEN = OPEN[1:]
        CLOSED.append(curr)  # store copy on CLOSED;

        print "%d. From OPEN... (%d) %s" % (k,curr.no,curr.state)

        # CORRECTION IN LAB: curr.thestate -> curr.state
        if goal_fct(curr.state):
            return True  
        else:
            neighs = successor_fct(curr.state) # successor "states"
            for n in neighs:
                if not on_OPEN(n,OPEN) and not on_CLOSED(n,CLOSED):
                    #CORRECTION IN LAB: curr.num --> curr.no
                    new_node = Node(NUM,curr.no,n,curr.depth + 1)
                    OPEN.append(new_node)
                    NUM += 1

            # CORRECTION/MODIFICATION IN LAB:  use the below ...
            # do NOT switch on sorting in reverse; 
            # sort OPEN in ascending order of eval fct values; low to high;
            OPEN.sort(key = lambda x: f_est(x))

        k += 1
    return False


# NEW:
# this function assumes that eval_fct defined in puzz8.py takes a
# representation of an 8-puzzle state (likely some sort of 2D array)
# as its argument;
def f_est(node):
    return node.depth + eval_fct(node.state)




        
        
        
    




    
          
                                                    
