# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 21:29:45 2019

@author: Muhammad Ahmed
"""

import re
import string
from nltk.tag import pos_tag
from nltk.stem.wordnet import WordNetLemmatizer

def lemmatize_sentence(tokens):
    sentence = []
    lematizer = WordNetLemmatizer()
    for word, tag in pos_tag(tokens):
        if tag.startswith('NN'):
            pos = 'n'
        elif tag.startswith('VB'):
            pos = 'v'
        else:
            pos = 'a'
        sentence.append( lematizer.lemmatize( word , pos ) )
    return sentence

def remove_noise(tokens , stop_words = ()):
    sentence = []
    for token, tag in pos_tag( tokens ):
        token = re.sub('http[s]?://(?:[a-zA-Z]|[0-9]|[$-_@.&+#]|[!*\(\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+' , '',token)
        token = re.sub("(@[A-Za-z0-9_]+)","",token)

        if tag.startswith("NN"):
            pos = 'n'
        elif tag.startswith('VB'):
            pos = 'v'
        else:
            pos = 'a'

        lemmatizer = WordNetLemmatizer()
        token = lemmatizer.lemmatize(token, pos)

        if len(token) > 0 and token not in string.punctuation and token.lower() not in stop_words:
            sentence.append( token.lower() )
    return sentence

def get_all_words(tokens_list):
    for tokens in tokens_list:
        for token in tokens:
            yield token

def get_tweets_for_model(tokens_list):
    for tweets in tokens_list:
        yield dict([token,True] for token in tweets)

