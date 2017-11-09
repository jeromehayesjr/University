# RedBlue_lab5.py
# by Jerome Hayes Jr, Feb 2017

# Homework Part 1 works perfectly.
# Homework Part 2 Didn't complete minimax


# TO BE COMPLETED IN LAB5 AND FOR HW2

import random
import copy

MAXTURNS = 10

# blue plays against red; player Blue to start

class RB():
    #redrow,redcolumn,bluerow,bluecolumn,
    def __init__(self, rr = None, rc = None, br = None, bc = None, tn = None):
        if br != None:
            r1 = rr
            c1 = rc
            r2 = br
            c2 = bc
            self.turn = tn
        else:
            r1 = random.randint(0,3)
            c1 = random.randint(0,3)
            r2 = random.randint(4,7)
            c2 = random.randint(4,7)
            self.turn = 'B'
        self.red = [r1,c1]
        self.blue = [r2,c2]
        self.no_turns = 0
        
    # I think this is how the reset function should be
    def reset(self, rr = None, rc = None, br = None, bc = None, tn = None):
        if br != None:
            r1 = rr
            c1 = rc
            r2 = br
            c2 = bc
            self.turn = tn
        else:
            r1 = random.randint(0,3)
            c1 = random.randint(0,3)
            r2 = random.randint(4,7)
            c2 = random.randint(4,7)
            self.turn = 'B'
        self.red = [r1,c1]
        self.blue = [r2,c2]
        self.no_turns = 0
        
    def present(self):
        for i in range(8):
            for j in range(8):
                if [i,j] == self.blue:
                    print 'B',
                elif [i,j] == self.red:
                    print 'R',
                else:
                    print "_",
            print ""
        print "\n"
        return

    # >>>>>>>>
    # interaction with human player, starts game;
    def play_B(self):
        self.present()
        while(True):
            pick = raw_input('Blue, which move?')
            if pick == "u":
                self.blue[0] = self.blue[0] - 1
                self.turn = "R"
                break
            elif pick == "d":
                self.blue[0] = self.blue[0] + 1
                self.turn = "R"
                break
            elif pick == "l":
                self.blue[1] = self.blue[1] - 1
                self.turn = "R"
                break
            elif pick == "r":
                self.blue[1] = self.blue[1] + 1
                self.turn = "R"
                break
            else:
                print "Can't do; choose again?"
        print self.present()


    # >>>>>>>>
    # the opponent (by program)
    def play_R(self):
        print "Playing R..."

        movered = ['u','d','l','r']
        random.shuffle(movered)
        
        if movered[1] == "u":
            if self.red[0] != 0:
                self.red[0] = self.red[0] - 1
                self.turn = "B"
            else:
                return None
            
        elif movered[1] == "d":
            if self.red[0] != 7:
                self.red[0] = self.red[0] + 1
                self.turn = "B"
            else:
                return None
            
        elif movered[1] == "l":
            if self.red[1] != 0:
                self.red[1] = self.red[1] - 1
                self.turn = "B"
            else:
                return None
            
        elif movered[1] == "r":
            if self.red[1] != 7:
                self.red[1] = self.red[1] + 1
                self.turn = "B"
            else:
                return None

    
    # >>>>>>>>
    # returns list of possible next game boards from the
    # viewpoint of the player whose turn it is;
    def next_moves(self):
        moves = []
        for i in range(8):
            for j in range(8):
                if self.turn == 'B':
                    if [i,j] != self.blue:
                        moves.append([i,j])
                elif self.turn == 'R':
                    if [i,j] != self.red or [i,j] != self.blue:
                        moves.append([i,j])
        random.shuffle(moves)
        return moves
    
    # >>>>>>>>          
    # minimax reasoning from opponent R's perspective;
    # ANALOGOUS TO minimax of tictactoe, but from the viewpoint
    # of the opponent; 
    def minimax(self):
        nextR = self.next_moves()
        if nextR == []:
            return None
        minBs = []
        for Rmove in nextR:
            self.turn = 'B'
            nextB = self.next_moves()
            minval = 10000
            minmove = None
            for Bmove in nextB:
                if Bmove.eval_fct() < minval:
                    return None
            
        
        

    # >>>>>>>>>
    # any other member functions that make be useful to you
    
    

    #  horiz diff + vertic diff; small is better for W
    #  NOTE: high values bad for human player, low value good for
    #  opponent; that makes minimax the right kind of reasoning for
    #  the opponent;
    def eval_fct(self):
        return abs(self.blue[0] - self.red[0]) +\
               abs(self.blue[1] - self.red[1])
    
    # True if blue wins; after B moved (turn switched to R) blue
    # captures red;
    def win_B(self):
        return self.turn == 'R' and self.blue == self.red

    # True if blue wins; B has not won, and the number of turn
    # exceeds MAXTURNS
    def win_R(self):
        return not self.win_B() and self.no_turns > MAXTURNS

    # True if R blundered; after R moved (turn switched to B), red has
    # run into blue;
    def loss_R(self):
        return self.turn == 'B' and self.red == self.blue

    def play(self):
        self.reset()
        print "\n\n"
        print "Starting a new game of Red&Blue. Blue begins ...\n"
        while True:
            #if self.no_turns != 0:
            #    print "B about to move on B:%s R:%s\n" % (self.blue,self.red)
            self.play_B()
            if self.win_B():
                self.present()
                print "Blue, you win  :-))\n\n"
                break
            if self.win_R():
                self.present()
                print "Red wins, you loose  :-((\n\n"
                break
            #print "R about to move on B:%s R:%s\n" % (self.blue,self.red)
            self.play_R()
            if self.loss_R():
                self.present()
                print "Freebie for Blue :-)))\n\n"
                break
            
        print "\n\n"
        print "This concludes another breath taking round of Red&Blue\n"
        return
    

            
def main():
    mygame = RB()
    mygame.play()

if __name__ == "__main__":
    main()

    

    
            

            

    
               
   
                                   
