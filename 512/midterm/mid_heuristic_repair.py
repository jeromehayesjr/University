# heuristic_repair.py

# CSE MIDTERM, Part 2, Take-Home, Winter 2017
# Started by Kerstin Voigt (Instructor)

# COMPLETED BY STUDENT: Jerome Hayes Jr <<<< Name here!!
# by due date: February 21, 2017, at lecture time

# Parts to be completed are marked with '<<<<< COMPLETE'
import random

N = 8
MAXSTEPS = 5000

# generates a random n-queens board
# representation: a list of length n the value at index i is
# row that contains the ith queen;
# exampe for 4-queens: [0,2,0,3] means that the queen in column 0 is
# sitting in row 0, the queen in colum 1 is in row, the queen in column 2
# is in row 0, and the queen in column 3 is in row  3;
def random_queens(n):
    queens = []
    for i in range(n):
        queens.append(random.randint(0,n-1))
    return queens

# displays the n-queens board as indicated by list qs
# example for 4-queens: [0,2,0,3] prints out as
#
# Q _ Q _ 
# _ _ _ _ 
# _ Q _ _ 
# _ _ _ Q   ... notice queens conflicts that need repair ...  

def show_nqueens(qs):
    for row in range(len(qs)):
        for col in range(len(qs)):
            if row == qs[col]:
                print 'Q',
            else:
                print '_',
        print ""
    return


# prints out the coordinates [row,col] for each queen on the board
# represented by list qs;

def queens_coords(qs):
    coords = []
    for col in range(len(qs)):
        coords.append([qs[col],col])
    return coords

# how many queens are in row k?
# = how many times does k appear in qs list?
# for the queens board [0,2,0,3] and each row, you get
#
# queens in row 0: 2
# queens in row 1: 0
# queens in row 2: 1
# queens in row 3: 1

def queens_in_row(k,qs):
    return qs.count(k)
    #return

# returns how many queens are in diagonals going through cell (row,col);
# also counts the queen that may be sitting in exactly (row,col)
# for the queens board [0,2,0,3] and each row, you get
#
# queens in diags through (0,0}: 2
# queens in diags through (0,1}: 0
# queens in diags through (0,2}: 1
# queens in diags through (0,3}: 1
# queens in diags through (1,0}: 1
# queens in diags through (1,1}: 3
# queens in diags through (1,2}: 1
# queens in diags through (1,3}: 1
# queens in diags through (2,0}: 1
# queens in diags through (2,1}: 1
# queens in diags through (2,2}: 2
# queens in diags through (2,3}: 0
# queens in diags through (3,0}: 1
# queens in diags through (3,1}: 0
# queens in diags through (3,2}: 1
# queens in diags through (3,3}: 2

def queens_in_diags(row,col,qs):
    k = 0
    for r in range(len(qs)):
        for c in range(len(qs)):
            if (row - r) == (col - c) or\
               (row - r) == -(col - c):
                if qs[c] == r:
                    k += 1
    return k

# given a column number (col) and the queens board qs, returns the
# number of conflicts in this colum for each row; 
# for column 0 of queens board [0,2,0,3] which prints as
#
# Q _ Q _ 
# _ _ _ _ 
# _ Q _ _ 
# _ _ _ Q
#
# you get conflicts [3,1,2,2,] in rows 0..3 of col 0;
# e.g., cell [0,0] is threatened by 3 queens, counting the
# one that is at [0,0] proper;

def column_conflicts(col,qs):
    colconf = []
    for r in range(len(qs)):
        conf = queens_in_row(r,qs) +\
               queens_in_diags(r,col,qs)
        if qs[col] == r:
            conf -= 1
        colconf.append(conf)
    return colconf

# returns the row index of the field in column numbered 'col' that is
# threatened by the smallest number of queens; for the above example
# with conflicts [3,1,2,2,] in rows 0..3 of col 0, this function returns
# row index 1 (field (1,0), row 1 in col 0, is threatened by the minimal number
# of queens, here: 1; 
def min_conflicts_row(col,qs):
    conf = column_conflicts(col,qs)
    return conf.index(min(conf))
    #<<<< COMPLETED (1)


# change qs so that the queen in column col is in row 'row; unless it already is
def column_repair(col,row,qs):
    qs[col] = row
    return

# returns True if there is at most one queen in every row and diagonal; False
# otherwise; (by virtue of the representation, it is a given that each column contains
# a single queen; thus no need to test for columns);
def queens_solved(qs):
    
    for row in range(len(qs)):
        if queens_in_row(row,qs) !=1:
            return False
        else:
            return True
    #<<<<< COMPLETED (2)

    
def hrepair(queens):
    step = 1
    print "Heuristic Repair  of:\n"
    show_nqueens(queens)
    print "\n\n"
    while True:
        if queens_solved(queens) == True:
            print "\n"
            print "SOLUTION!!"
            show_nqueens(queens)
            break
            # <<<<< COMPLETE (3)
    
        if step > MAXSTEPS:
            print "Could not solve!"
            break
        
        for i in range(len(queens)):
            targetrow = min_conflicts_row(i,queens)
            print "[%d] col %d: min conflicts in row %d" % (step,i,targetrow)

            column_repair(i,targetrow,queens)
            print "move queen to row %d" % (i)
            print "\n"
            # <<<<< COMPLETED (5)
            
            step += 1
    return

    
        
def main():
     n = int(raw_input("How many queens: "))
     qs = random_queens(n)
     hrepair(qs)

if __name__ == "__main__":
    main()
    
             
    



    

    








