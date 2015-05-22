
'''
Created on 20.05.2015

@author: Tugrul
'''


class Parser:
    position =0
    counter = 0 
    positionReached = True
    clamp = False
    clampOpenCounter = 0
    clampCloseCounter = 0
    termVal = None
    constantVal = None
    expressionVal = None
    firstVal = 0
    calcA = []
    secoundVal = 0
    equationBool = False
    ergGanz = 0
    
    def parse(self, input):
        i = input[self.position]
        return self.equation(i, input, self.position)
    #Checking if there is on the begining a open-clamp or a diget 0-9 
    #if there is one
    def equation(self, i, input, position):
            while self.positionReached:
                if position == 0:
                    if i > "0" and i<="9" or "(":
                        
                        self.expression(i, input, position)
                        
                    
                    else:
                        raise ValueError("No 0 ist allowed at the beginn")  
                        self.positionReached = False  
                
                else:
                    
                    if i != None:
                        if i >= "0" and i<="9":
                            self.expression(i, input, position)
                        elif i == "=":
                            if position+1 != len(input):
                                if input[position+1] != None:
                                    
                                    self.counter = self.counter + 1
                                    if self.counter >= 2:
                                        raise ValueError("there are to many '='")
                                        self.positionReached = False;
                                    else:
                                                                               
                                        newIndex = position+1
                                        i = input[position+1]
                                        self.equation(i, input, newIndex)
                                else:
                                    raise ValueError("After '=' it has to be a symbol! Please check your input...")
                                    self.positionReached = False
                            else:
                                raise ValueError("Indexfailure: After this symbol = it has to available a expression! Please check your input...")
                        
                        elif i == "+" or i == "*":
                            
                            self.expression(i, input, position) 
                            
                        elif i == "(":
                            
                                if input[position+1] != "(":
                                    if input[position+1] != "*":
                                        if input[position+1] != "+":
                                            if input.find(")") != -1:
                                                while self.clamp == False:
                                                    if i != ")":
                                                        if i == "(" or i == "+" or i == "*": 
                                                            self.expression(i, input, position)
                                                            position = position + 1
                                                            if position != len(input): 
                                                                i = input[position]
                                                            else:
                                                                self.positionReached = False
                                                                print("Fertig")
                                                        else:
                                                            
                                                            self.expression(i, input, position)
                                                            position = position + 1
                                                            if position != len(input): 
                                                                i = input[position]
                                                            else:
                                                                if input.find(")") != -1:
                                                                    self.clamp = True
                                                                    self.positionReached = False
                                                                    
                                                            
                                                    elif i == ")":
                                                        self.clamp = True
                                                        self.expression(i, input, position)
                                            else:
                                                self.positionReached = False
                                                raise ValueError("No closing clamp found ')', invalid!")
                                        else:
                                            raise ValueError("after clamp there cant be a '+'!")
                                            self.positionReached = False
                                    else:
                                        raise ValueError("after clamp there cant be a '*'")
                                        self.positionReached = False;
                                else: 
                                    raise ValueError("there shouldnt be again a clamp after a clamp!")
                                    self.positionReached = False;
                        else :
                            raise ValueError("Your input is invalid! Please check your input")  
                            self.positionReached = False  
                              
                    else:
                        raise ValueError("Your input is invalid! Please check your input")
                        self.positionReached = False
                
                position = position + 1



                self.clamp=False
                if position != len(input) and position <= len(input): 
                    i = input[position]
                else:
                    self.positionReached = False
                    if self.clampOpenCounter != self.clampCloseCounter:
                        
                        raise ValueError("Fail! You missed out a Clamp!!")
                    elif "=" in input:
                        self.calculating( input, position)
                                                   

    
        
    def expression(self, i, input, position):
        if position != 0:   
            if i == "+":
                position = position + 1  
                if position != len(input):
                    if input[position] == "0" or input[position] == "1" or input[position] == "2" or input[position] == "3" or input[position] == "4" or input[position] == "5" or input[position] == "6" or input[position] == "7" or input[position] == "8" or input[position] == "9" or input[position] == "(" or input[position] == ")":
                        "true"
                    else:
                        raise ValueError("Your input is invalid. Please check your input")
                else: 
                    raise ValueError("after a '+' should be 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 or 0")
            elif i == "(":
                self.factor(i, input, position)
            elif i == ")":
                self.factor(i, input, position)
            elif i == "*":  
                self.term(i, input, position)
                
            else:
                self.expressionVal = self.term(i,input, position)     
        else:
            self.expressionVal = self.term(i, input, position)
        return self.expressionVal
        
    def factor(self, i, input, position):
        if i == "(":
            "true"
            self.clampOpenCounter = self.clampOpenCounter+1 
            '------------------------------------------------------------------------ counter 1 ---------------'
            
        elif i == ")":  
            "true"
            self.clampCloseCounter = self.clampCloseCounter+1
            '------------------------------------------------------------------------ counter 2 ---------------'                    
        else:
            self.constant(i, input, position)
            
     
    def constant(self, i, input, position):
        if i == "0":
            self.constantVal = self.isDigit(i)
        else:
            self.constantVal = self.isDigitWOZero(i)   
        
        return self.constantVal
    
    def term(self, i, input, position):  
        if position != 0:
            if i == "*":
                position = position + 1  
                if position != len(input):
                    if input[position] == "0" or input[position] == "1" or input[position] == "2" or input[position] == "3" or input[position] == "4" or input[position] == "5" or input[position] == "6" or input[position] == "7" or input[position] == "8" or input[position] == "9" or input[position] == "(" or input[position] == ")":
                        "true"
                else:
                    raise ValueError("Nach einem * muss eine Ziffer kommen")
            elif i == "(" or i == ")":
                self.termVal = self.factor(i, input, position)
            
            else:
                self.termVal = self.factor(i, input, position)
        else:
            self.termVal = self.factor(i, input, position)
        
        return self.termVal
    
    def isDigitWOZero(self, i):  
        isIn = True 
        if i == "1" or i == "2" or i == "3" or i == "4" or i == "5" or i == "6" or i == "7" or i == "8" or i == "9":
            "true"
        elif i != "1" or "2" or "3" or "4" or "5" or "6" or "7" or "8" or "9":
            isIn = False
            
    
    
            
    def isDigit(self, i):  
        isIn = True;
            
        if i == "0":
            "true"
        else:
            self.isDigitWOZero(i)
            
    def calculating(self, input, position):
        if(input.find("(")):
            k = input.find("(")
            endOfClamp = input.find(")")
            for u in range(k, endOfClamp):
                z = input[u]
                if(z=="*"):
                    vorM=input[u-1]
                    nachM=input[u+1]
                    ergM = int(vorM)*int(nachM)
                    for rest in range(k+1, u):
                        if(input[rest]>="0" and input[rest]<="9"  ): #0-9
                            if(input[rest+1]=="+"):
                                klammerAnf = input[rest]
                                self.ergGanz = int(klammerAnf)+int(ergM)
                                print(self.ergGanz)
                    
        self.position = 0
        if(input.find("=")):
            inputLength = len(input)
            for o in range(0,input.find("=")+1):
                i = input[o]
                if i == "=":
                    for u in range(o,inputLength):
                        k = input[u]
                        if k == "1" or k == "2" or k == "3" or k == "4" or k == "5" or k == "6" or k == "7" or k == "8" or k == "9" or k == "0":
                            kInt = int(k)
                            self.secoundVal = self.secoundVal+kInt
                if i == "1" or i == "2" or i == "3" or i == "4" or i == "5" or i == "6" or i == "7" or i == "8" or i == "9" or i == "0":
                    iInt = int(i)
                    self.firstVal = self.firstVal+iInt
                    
            if(self.firstVal==self.secoundVal):
                self.equationBool = True
            else:
                self.equationBool = False
                
        print(self.equationBool)                      
    
if __name__ == '__main__':
    p1 = Parser()
    print(p1.parse("1+(4+5*6)=3+1"))
    