#lab8.py
#Jerome Hayes Jr & Marc Victoria

from operator import truediv

data = [{'Appraisal':1,'Rating':0,'Income':0, 'Balance':1,'Loan_Ok':0}, \
        {'Appraisal':0,'Rating':0,'Income':1, 'Balance':0,'Loan_Ok':0}, \
        {'Appraisal':1,'Rating':1,'Income':0, 'Balance':1,'Loan_Ok':1}, \
        {'Appraisal':0,'Rating':1,'Income':1, 'Balance':1,'Loan_Ok':1}, \
        {'Appraisal':0,'Rating':1,'Income':1, 'Balance':0,'Loan_Ok':0}, \
        {'Appraisal':1,'Rating':1,'Income':1, 'Balance':0,'Loan_Ok':1}, \
        {'Appraisal':1,'Rating':1,'Income':1, 'Balance':1,'Loan_Ok':1}, \
        {'Appraisal':1,'Rating':0,'Income':1, 'Balance':0,'Loan_Ok':0}, \
        {'Appraisal':1,'Rating':1,'Income':0, 'Balance':0,'Loan_Ok':0}\
        ]

individual = [1,2,3,4,5,6,7,8,9]

length_of_data = len(data)


#return list of the individual where loan_ok is 1.
def Loan_ok():
    ok = []
    for i in individual:
        if(data[i-1]['Loan_Ok']== 1):
            ok.append(i)
    return ok

#For a single attribute enter, this returns
#a list of individuals that have an "1", without Loan_Ok.
def attribute_pos(attr):
    pos_individual = []
    for i in individual:
        if(data[i-1][attr] == 1):
            pos_individual.append(i)
    return pos_individual

#For two attribute enter, this returns a list of individuals
#that have an "1", without Loan_Ok
def two_attribute_pos(attr1,attr2):
    pos_individual = []
    for i in individual:
        if (data[i-1][attr1] == 1) and (data[i-1][attr2] == 1):
            pos_individual.append(i)
    return pos_individual

#For three attribute
def three_attribute_pos(attr1,attr2,attr3):
    pos_individual = []
    for i in individual:
        if (data[i-1][attr1] == 1) and (data[i-1][attr2] == 1) and (data[i-1][attr3] == 1):
            pos_individual.append(i)
    return pos_individual    

#For a single attribute enter, returs a list of individuals that have
# an "1", with Loan_Ok.
def attribute_pos_with_ok(attr):
    pos_with_ok = []
    for i in individual:
        if(data[i-1][attr] == 1) and (data[i-1]['Loan_Ok']== 1):
            pos_with_ok.append(i)
    return pos_with_ok

#For two attribute enter, returs a list of individuals that have
# an "1", with Loan_Ok.
def two_attribute_pos_with_ok(attr1,attr2):
    pos_with_ok = []
    for i in individual:
        if(data[i-1][attr1] == 1) and (data[i-1][attr2] == 1) and (data[i-1]['Loan_Ok']== 1):
            pos_with_ok.append(i)
    return pos_with_ok

#For three attribute
def three_attribute_pos_with_ok(attr1,attr2,attr3):
    pos_with_ok = []
    for i in individual:
        if(data[i-1][attr1] == 1) and (data[i-1][attr2] == 1) and(data[i-1][attr3] == 1) \
                            and (data[i-1]['Loan_Ok']== 1):
            pos_with_ok.append(i)
    return pos_with_ok

#return the enter attribute ratio: attribute with ok / attribute
def ratio(attr):
    if len(attribute_pos_with_ok(attr)) == 0:
        return 0
    else:
        return truediv(len(attribute_pos_with_ok(attr)), len(attribute_pos(attr)))

def ratio2(attr1,attr2):
    if len(two_attribute_pos(attr1,attr2)) == 0:
        return 0
    else:
        return truediv(len(two_attribute_pos_with_ok(attr1,attr2)), len(two_attribute_pos(attr1,attr2)))

def ratio3(attr1,attr2,attr3):
    if len(three_attribute_pos_with_ok(attr1,attr2,attr3)) == 0:
        return 0
    else:
        return truediv(len(three_attribute_pos_with_ok(attr1,attr2,attr3)), len(three_attribute_pos(attr1,attr2,attr3)))


def solution():
    
    keys = ['Appraisal','Rating','Income', 'Balance']
    ratios =[]
    winning_attr = []
    rules = []
    #1 Attributes
    #creates a list of the attributes ratios
    for attr in keys:
        ratios.append(ratio(attr))           
    #finds the hightest ratio from the list of attribute
    for i in range(len(ratios)):
        #search matching ratio value
        if max(ratios) == ratios[i]:
            #append matching ratio attribute name
            winning_attr.append(keys[i])
            #remove the winning attr from the keys
            keys.pop(i)
            #return winning_attr
            print "\n\n"
            print "%s covers %s out of %s with LOAN_OK" % \
                (winning_attr[0], attribute_pos_with_ok(winning_attr[0]), Loan_ok())
            break

    if max(ratios) != 1.0:
        ratios[:] = []
        # 2 Attributes
        #creates a list of the 2 attributes together ratios
        for attr in keys:
            ratios.append(ratio2(winning_attr[0],attr))
        #finds the highest ratio from the list of 2 attribute
        for i in range(len(ratios)):
            #search matching ratio value
            if max(ratios) == ratios[i]:
                #append matching ratio attribute name
                winning_attr.append(keys[i])
                #remove the winning attr from the keys
                keys.pop(i)
                #return winning_attr
                print "\n"
                print "%s and %s covers %s out of %s with LOAN_OK" % \
                    (winning_attr[0],winning_attr[1], \
                    two_attribute_pos_with_ok(winning_attr[0],winning_attr[1]), Loan_ok())
                break
    if max(ratios) != 1.0:
        ratios[:] = []
        # 3 Attributes
        #creates a list of the 3 attributes together ratio
        for attr in keys:
            ratios.append(ratio3(winning_attr[0],winning_attr[1],attr))
        #finds the highest ratio from the list of 3 attribute
        for i in range(len(ratios)):
            #search matching ratio value
            if max(ratios) == ratios[i]:
                #append matching ratio attribute name
                winning_attr.append(keys[i])
                #remove the winning attr from the keys
                keys.pop(i)
                #return winning_attr
                print "\n"
                print "%s , %s ,and %s covers %s out of %s with LOAN_OK" % \
                    (winning_attr[0],winning_attr[1],winning_attr[2], \
                    three_attribute_pos_with_ok(winning_attr[0],winning_attr[1], winning_attr[2]), Loan_ok())
                break
    

    #Checks if ratio is a prefect 1.0
    if max(ratios) == 1.0:
        #add the finish rule to rules
        rules.append(winning_attr)
        print "\n"
        print "*This is a rule %s *" % (rules)
        #deletes individuals that were meet
        stuff = attribute_pos_with_ok(winning_attr[0])
        for i in stuff:
            individual.remove(i)
            
        winning_attr[:] = [] #set winning_attr to empty

        if len(Loan_ok()) > 0:
            solution()


    if max(ratios) != 1.0:
        print "\n\n"
        print "Could not solve"

                  
#returns the key aka attributes
def key():
    values = []
    for dictory in data:
        for test in dictory.keys():
            values.append(test)
        values.remove('Loan_Ok')
        break
    return values

def main():
    solution()

if __name__ == "__main__":
    main()
