#hobbits and orcs.py

START = [[3,3],[0,0],'left']

GOAL = [[0,0],[3,3], 'right']

def goal_fct(state):
    return None

def successor_fct(state):
    succ = []
    if state[2] == 'right':
        succs.append(hh_2left(state))
        succs.append(o_2left(state))
        succs.append(o_1left(state))
        succs.append(h_1left(state))
    return None

def eval_fct(state):
    return cmp(state,GOAL)

def show_state(state):
    return None

