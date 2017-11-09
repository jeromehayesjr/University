# graph_search.py
# Kerstin Voigt, Jan 2017, after Nils Nilsson's Graph Search Algorithm

# to be used in Lab3;

import random
from hw1_puzz8 import *
#from hobbits_and_orcs import *

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
LIMIT = 2500
# search to GOAL from state start

# the following domain/problem dependent functions will need to be
# provided (here: imported from puzz8.py):
#
# goal_fct(x): True for state x that is 8-puzzle solution
# successor_fct(x): list of immediate successor states of state x
# eval_fct(x): evaluation function to rate state x; example: #tiles out of place;

OPEN = []
CLOSED = []

# modes: DFS, BFS, BEST, A*   <<<<<< NEW
def graphsearch(start, mode = 'A*'):
    global NUM
    global OPEN
    global CLOSED
    random.seed()  #<<<<<<<< NEW
    NUM = 1
    start_node = Node(NUM,None,start,0,eval_fct(start)) # casting start "node"
    NUM += 1
    # OPEN: a list of all (partial) paths seen until now
    # initial to path to starting point, [x] 
    OPEN = [start_node]
    CLOSED = []
    k = 1
    neighs = []
    while OPEN != []:
        if k > LIMIT:
            break
        curr = OPEN[0]
        OPEN = OPEN[1:]
        CLOSED.append(curr)  # store copy on CLOSED;

        print "%d. From OPEN... (%d)[%d] %s\n" % (k,curr.no,curr.eval,curr.state)

        # CORRECTION IN LAB: curr.thestate -> curr.state
        if goal_fct(curr.state):
            #return True
            
            path = compute_path(curr,CLOSED) # <<<<<< NEW
            print "Solution Path:"
            show_path(path)
            print "\n"
            print "Iterations: %d  Nodes generated: %d  Length of SolnPath: %d" %\
                  (NUM-1, k, len(path))
            return True
            
        else:
            neighs = successor_fct(curr.state) # successor "states"
            random.shuffle(neighs) # <<<<<<< NEW
            for n in neighs:
                if not on_OPEN(n,OPEN) and not on_CLOSED(n,CLOSED):
                    #CORRECTION IN LAB: curr.num --> curr.no
                    new_node = Node(NUM,curr.no,n,curr.depth + 1,eval_fct(n))
                    if mode == 'DFS':
                        OPEN = [new_node] + OPEN  #<<<<<<<<< NEW
                    else:
                        OPEN.append(new_node)
                    NUM += 1

            # CORRECTION/MODIFICATION IN LAB:  use the below ...
            # do NOT switch on sorting in reverse; 
            # sort OPEN in ascending order of eval fct values; low to high;

            if mode == 'A*':
                OPEN.sort(key = lambda x: f_est(x))    # <<<< NEW
            elif mode == 'BFS':
                OPEN.sort(key = lambda x: x.depth)     # <<<< NEW
            elif mode == 'BEST':
                OPEN.sort(key = lambda x: x.eval)      # <<<< NEW
            else:
                pass
        k += 1
    
    if OPEN == []:
        print "This problem has no solution"
    else:
        print "Giving up after %d iterations and %d nodes" %(k,NUM)
    return False

# this function assumes that eval_fct defined in puzz8.py takes a
# representation of an 8-puzzle state (likely some sort of 2D array)
# as its argument;
def f_est(node):
    return node.depth + eval_fct(node.state)
    #return node.depth
    #return eval_fct(node.state)

# <<<< NEW 
def compute_path(goal,closed):
    path = [goal]
    pno = goal.parno
    while pno != None:
        #print "looking parent with .no %d" % pno
        parent = find_parent(pno, closed)
        path = [parent] + path
        pno = parent.parno
    return path

def find_parent(pno, nodes):
    for x in nodes:
        if x.no == pno:
            return x
    return None

def show_path(nodes):
    for i in range(len(nodes)):
        print "%d)" % (i+1),
        show_state(nodes[i].state)
    return


    



        
        
        
    




    
          
                                                    
