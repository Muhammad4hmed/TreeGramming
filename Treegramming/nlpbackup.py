# -*- coding: utf-8 -*-
"""
Created on Fri Dec  6 16:18:01 2019

@author: Muhammad Ahmed
"""

import nltk
import sys
import random
import re,string
from nltk.corpus import twitter_samples
from nltk.corpus import stopwords
from nltk.tag import pos_tag
from nltk.tokenize import word_tokenize
from nltk.corpus import twitter_samples
from nltk import classify
from nltk import NaiveBayesClassifier
from nltk import FreqDist
from nltk.stem.wordnet import WordNetLemmatizer

positive_tweets = twitter_samples.strings('positive_tweets.json')
negative_tweets = twitter_samples.strings('negative_tweets.json')
text = twitter_samples.strings('tweets.20150430-223406.json')

tweet_tokens = twitter_samples.tokenized('positive_tweets.json')

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
        
stop_words = stopwords.words('english')

positive_tweet_tokens = twitter_samples.tokenized('positive_tweets.json')
negative_tweet_tokens = twitter_samples.tokenized('negative_tweets.json')

positive_cleaned_tokens_list = []
negative_cleaned_tokens_list = []

for tokens in positive_tweet_tokens:
    positive_cleaned_tokens_list.append(remove_noise(tokens, stop_words))

for tokens in negative_tweet_tokens:
    negative_cleaned_tokens_list.append(remove_noise(tokens, stop_words))
    
all_pos_words = get_all_words( positive_cleaned_tokens_list )
all_neg_words = get_all_words( negative_cleaned_tokens_list )

freq_dis_pos = FreqDist( all_pos_words )
freq_dis_neg = FreqDist( all_neg_words )

positive_tokens_for_model = get_tweets_for_model(positive_cleaned_tokens_list)
negative_tokens_for_model = get_tweets_for_model(negative_cleaned_tokens_list)

pos_dataset = [(tweets,"Positive") for tweets in positive_tokens_for_model]
neg_dataset = [(tweets,"Negative") for tweets in negative_tokens_for_model]

dataset = pos_dataset + neg_dataset
random.shuffle(dataset)

train_data = dataset[:7000]
test_data = dataset[7000:]

classifier = NaiveBayesClassifier.train(train_data)

custom_tweet = sys.argv[1]
custom_tokens = remove_noise(word_tokenize(custom_tweet))

res = classifier.classify(dict([token, True] for token in custom_tokens))
print(res)

f = open( "result.txt" , "w" )
f.write(res)
f.close() 
