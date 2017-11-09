#lab2.py

#nesting
nlst = [1,2,[3],4,[5,[6,7]], [8,[[9]], 10]]

def nesting(nlst):
    if nlst == []:
        print '#'
        return
    nesting1(-1,nlst)

def nesting1(k,nlst):
    if nlst == []:
        for i in range(k):
            print "_",
        print '#'
        return
    if not type(nlst) == list:
        for i in range(k):
            print "_",
        print nlst
        return
    map(lambda x: nesting1 (k+1,x), nlsnt)
    return

#make_bst
def make_bst(k):
    bst = []
    if k <= 0:
        return []
    for i in range (k):
        name = raw_input("Name: ")
        insert_bst(name,bst)
    return bst

#insert_bst
def insert_bst(x,bst):
    if bst == []:
        bst.append(x)
        bst.append([])
        bst.append([])
    elif x < bst [0]:
        insert_bst(x,bst[1])
    elif x > bst[0]:
        insert_bst(x,bst[2])
    else:
        pass

#inorder_bst
mybst = ['nils', ['lars', ['aaron', [], ['hannah', [],[]]], []],\
         ['nolan',[], []]]

#list contents of bst in inorder (left-root-right)

def inorder_bst(bst):
    if bst == []:
        return
    if bst[1] != []:
        inorder_bst(bst[1])
    print bst[0]
    if bst[2] != []:
        inorder_bst(bst[2])

#dfs_bst
def dfs_bst(bst):
    if bst == []:
        return
    open = [bst[0]]
    while True:
        if open == []:
            return
        curr = open[-1]
        open = open[:-1]
        print curr
        succ = successors(curr,bst)
        open = succs + open
    return

#bfs_bst
def bfs_bst(bst):
    if bst == []:
        return
    open = [bst[0]]
    while True:
        if open == []:
            return
        curr = open[-1]
        open = open[:-1]
        print curr
        succ = successors(curr,bst)
        open = open + succs
    return

#successor function... only for binary trees
def successors(x,bst):
    if bst == []:
         return []
    if bst[0] == x:
         succs = []
         if bst[1] != []:
             succs.append(bst[1][0])
         if bst[2] != []:
             succs.append(bst[2][0])
         return succs
