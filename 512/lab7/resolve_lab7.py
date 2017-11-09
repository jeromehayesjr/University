#resolve_lab7.py
#Jerome Hayes Jr

from collections import OrderedDict #importing function to get rid of duplicates

#test example
CLS = [['notP' 'notQ, R'], ['P','R'], ['Q','R'], ['notR']]

#are clauses (lists of disjuncts) the same, i.e., they contain the exact
#same literals (variables) but is possibly different order: True or False
def same_clauses(c1,c2):
    while True:
        for literal in range(len(c1)):
            for c1[literal] in c2:
                return True
            else:
                return False
                break

#create complement: 'A' --> 'notA, 'notA' --> 'A'

#are x and y complements of each other? e.g., 'A' and 'notA'; True or False
def complementary (x, y):
    if x == "not" + y or y== "not" + x: #checks is they are same letter one with not other without
        return True
    else:
        return False
#done JHJ

#for two clauses c1 and c2  with complements, combine c1 and c2 minus the
#complementary literals;

def resolve(c1,c2):
    for x in c1:
        for y in c2:
            if complementary(x,y) == True:
                c1.remove(x)
                c2.remove(y)
    mergedlist = c1 + c2
    return no_duplicates(mergedlist)
#done JHJ

#remov duplicates form claues c; e.g.,(R,P,P) --> (R,P)
def no_duplicates(c):
    i=list(OrderedDict.fromkeys(c))
    return i
#done JHJ

def theorem (clause):
    while True:
        size = len(clause)
        i = 0
        if size-1 > i:
            c1 = clause[i]
            c2 = clause[i+1]
            c3=resolve(c1,c2)
            if c3 == []:
                print "UNSATISFIABLE"
                return False
            for literals in clause: #checking to make sure c3 is not in cls
                if c3 == literals:
                    c3 = []
                    print "No Contradiction: Satisfiable"
                    return False
            if c3 != []: #if not in cls append to c3
                clause.append(c3)
                size - size + 1
            i = i+2

        elif:
            return False
