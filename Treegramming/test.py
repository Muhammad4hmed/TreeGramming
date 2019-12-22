# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 21:31:02 2019

@author: Muhammad Ahmed
"""

import sys
import pickle
from nltk import classify
from nltk.tokenize import word_tokenize

from utils import remove_noise

#### ADD THESE TO LOAD THE CLASSIFIER ####
with open('model.pickle', 'rb') as fin:
    classifier = pickle.load(fin)

custom_tweet = sys.argv[1];
custom_tokens = remove_noise(word_tokenize(custom_tweet))
res = classifier.classify(dict([token, True] for token in custom_tokens))
print(res)
f = open( "result.txt" , "w" )
f.write(res)    
f.close() 
