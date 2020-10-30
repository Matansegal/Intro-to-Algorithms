# -*- coding: utf-8 -*-
"""
Created on Mon Apr  6 21:52:27 2020

@author: matan
"""
import random

nodesNum = [10,50,100,200,500]
density= ["low","dens"]

for n in nodesNum:
    for d in density:
        name = 'graph' + str(n) + d + '.txt'
        f = open(name, "w")
        f.write(str(n) + '\n')   # write num of elements
        char = 'A'
        charList = []
        for i in range(n): # for loop to write elements
            f.write(char + '\n')
            charList.append(char)
            if(char[-1] == 'Z'):
                if(char == 'Z'):
                    char = 'AA'
                elif(char == 'ZZ'):
                    char = 'AAA'
                else:
                    if (char[-2:] == 'ZZ'):
                        char = chr(ord(char[0]) + 1) + 'AA'
                    else:
                        char = chr(ord(char[0]) + 1) + 'A'
            else:
                char = char[:-1] + chr(ord(char[-1]) + 1)
                
        f.write('\n')
        
        pairList = [] # so it wont repeat pairs
        
        if d == "low":
            m = min(n-5,15) # man in the rand of connections
        else:
            m = max(n/10,30)
        
        for i in range(n):
            for j in range(random.randint(1, m)):
                randIndex = random.randint(0, n-1)
                if ((charList[i],charList[randIndex]) not in pairList and 
                    (charList[randIndex],charList[i]) not in pairList and
                    randIndex != i):
                    f.write(charList[i] + ' ' + str(random.randint(1, 100)) + # the weight
                        ' ' + charList[randIndex] + '\n')
                    pairList.append((charList[i],charList[randIndex]))
        
        f.close()
    
