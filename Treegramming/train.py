# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 21:30:20 2019

@author: Muhammad Ahmed
"""
import random
import pickle
from utils import *
from nltk import FreqDist
from nltk.corpus import stopwords
from nltk import NaiveBayesClassifier
from nltk.corpus import twitter_samples


positive_tweets = twitter_samples.strings('positive_tweets.json')
negative_tweets = twitter_samples.strings('negative_tweets.json')
text = twitter_samples.strings('tweets.20150430-223406.json')

tweet_tokens = twitter_samples.tokenized('positive_tweets.json')

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

train_data = dataset

classifier = NaiveBayesClassifier.train(train_data)

#### ADD THESE TO SAVE THE CLASSIFIER ####
with open("model.pickle", "wb") as fout:
    pickle.dump(classifier, fout)
