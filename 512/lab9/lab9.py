#lab9.py
#Jerome Hayes Jr

data = [{'size':'small', 'color':'red', 'Form':'ball','Class': 'pos'}, \
        {'size':'small', 'color':'blue', 'Form':'ball','Class': 'neg'}, \
        {'size':'large', 'color':'red', 'Form':'ball','Class': 'pos'}, \
        {'size':'large', 'color':'red', 'Form':'brick','Class': 'neg'}, \
        ]

attribs = {'size':['small','large'], \
           'color': ['red','blue'], \
           'form': ['ball', 'brick']}


G = {}
S = {}
N = []
P = []

def algorithm():
    for i in range (len(data)):
        S = data[i]
        
        if S['Class'] == 'pos':
            P.append(data[i])
            #need to add line to Delete all memers of G that fail to match S
                        
        if S == G:
            break

        if S['Class'] == 'neg':
            N.append(data[i])
            

        
        

def is_var(x):
    all_vals = []
    for k in attribs.keys():
        all_vals.extend(attribs(k))
    return not x in all_vals

def is_pos(inst):
    return inst['inst'] == 'pos'

def is_neg(inst):
    return inst['inst'] == 'neg'

#is concept conc1 more general than conc2
def is_more_general(conc1, conc2):
    attribs = ATTRIBS.keys()
    for att in attribs:
        if not is_variable(conc1[att]):
            if conc1[att] != conc2[att]:
                return False
    return True

def is_more_specific(conc1,conc2):
    return

def matches(conc1,conc2):
    return
