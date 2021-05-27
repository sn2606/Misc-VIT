#!/usr/bin/env python
# coding: utf-8

# In[1]:


# importing libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import copy
get_ipython().run_line_magic('matplotlib', 'inline')


# In[2]:


tsa = pd.read_csv("twitter_sentiment_data.csv")
tsa.head()


# In[3]:


tsa.drop("sentiment", axis=1, inplace=True)
tsa.head()


# ### LENGTH OF TWEET

# In[4]:


fig = plt.figure(figsize=(10, 10))
tsa['message'].str.len().hist()
fig.savefig("hist-length-of-tweet.png", bbox_inches = 'tight')


# ### NUMBER OF WORDS IN A TWEET

# In[5]:


fig = plt.figure(figsize=(10, 10))
tsa['message'].str.split().map(lambda x : len(x)).hist()
fig.savefig("hist-no-words-of-tweet.png", bbox_inches = 'tight')


# ### AVERAGE WORD LENGTH IN A TWEET

# In[6]:


fig = plt.figure(figsize=(8, 8))
obj = tsa['message'].str.split().apply(lambda x : [len(i) for i in x])
obj = obj.map(lambda x : np.mean(x)) #map is only for pandas objects
obj.hist()
fig.savefig("hist-avg-wordlen-of-tweet.png", bbox_inches = 'tight')


# ### FREQUENCY OF THE STOP WORDS

# In[7]:


# import re
import nltk
# nltk.download('stopwords')
from nltk.corpus import stopwords
stop = set(stopwords.words('english'))
# stop


# In[8]:


corpus = []
twt = tsa['message'].str.split()
twt = twt.values.tolist()
corpus = [word for i in twt for word in i]
# corpus


# In[9]:


from collections import defaultdict
dic = defaultdict(int)

for word in corpus:
    if word in stop:
        dic[word] = dic[word] + 1
        
# dic


# In[10]:


fig = plt.figure(figsize = (20, 10))
top = sorted(dic.items(), key=lambda x:x[1],reverse=True)[:20] 
x,y = zip(*top)
plt.bar(x,y)
fig.savefig("top-stopwords-bar.png", bbox_inches="tight")


# ### FREQUENCY OF WORDS OTHER THAN STOPWORDS

# In[11]:


import collections
from collections import Counter
import re

def username_filter(word):
    if(re.search("^@", word) == None and re.search("^((http|https)\:\/\/)", word) == None 
       and re.search("^&amp;$", word) == None and word != "RT" and word != "|" and word != "-"):
        return True
    else:
#         print(word)
        return False
    
filtered_corpus = filter(username_filter, corpus)
filtered_corpus = list(filtered_corpus)
# filtered_corpus


# In[12]:


counter = Counter(filtered_corpus)
most = counter.most_common()
# most[:100]

# print(len(most))

x, y= [], []
for word,count in most[:125]:
    if (word not in stop):
        x.append(word)
        y.append(count)
        
# print(len(x)) 
fig = plt.figure(figsize = (20, 10))
plt.xticks(rotation = 90)
plt.xlabel("Words")
plt.ylabel("Count")
sns.barplot(x = x, y = y)
fig.savefig("freq-words-barplot.png", bbox_inches = "tight")


# ### MOST FREQUENT N-GRAMS

# In[13]:


from sklearn.feature_extraction.text import CountVectorizer
def get_top_ngram(corpus, n=None):
    vec = CountVectorizer(ngram_range=(n, n)).fit(corpus)
    bow = vec.transform(corpus)
    sum_words = bow.sum(axis=0) 
    words_freq = [(word, sum_words[0, idx]) for word, idx in vec.vocabulary_.items()]
    words_freq = sorted(words_freq, key = lambda x: x[1], reverse=True)
    return words_freq[:140]


# In[14]:


vec = CountVectorizer(ngram_range = (2, 2)).fit(filtered_corpus)
bow = vec.transform(filtered_corpus)
sum_words = bow.sum(axis = 0)
words_freq = [(word, sum_words[0, idx]) for word, idx in vec.vocabulary_.items()]
words_freq = sorted(words_freq, key = lambda x: x[1], reverse=True)
# words_freq


# In[15]:


top_n_bigrams=get_top_ngram(tsa['message'],2)[:30]
print(top_n_bigrams)
x,y=map(list,zip(*top_n_bigrams)) 
fig = plt.figure(figsize = (20, 10))
plt.xticks(rotation = 90)
plt.xlabel("Bigrams")
plt.ylabel("Count")
sns.barplot(x = x, y = y)
fig.savefig("freq-bigrams-barplot.png", bbox_inches = "tight")


# In[16]:


top_n_trigrams=get_top_ngram(tsa['message'],3)[:25]
print(top_n_trigrams)
x,y=map(list,zip(*top_n_trigrams)) 
fig = plt.figure(figsize = (20, 10))
plt.xticks(rotation = 90)
plt.xlabel("Trigrams")
plt.ylabel("Count")
sns.barplot(x = x, y = y)
fig.savefig("freq-trigrams-barplot.png", bbox_inches = "tight")


# ### TOPIC MODELLING WITH pyLDAvis

# In[17]:


import nltk
import gensim
from nltk.stem import PorterStemmer
from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize
from nltk import punkt
from nltk import wordnet
# nltk.download('punkt')
# nltk.download('wordnet')


# In[18]:


def preprocess_tweets(df):
    corpus = []
    stem = PorterStemmer()
    lem = wordnet.WordNetLemmatizer()
    for tweet in df['message']:
        words = [w for w in word_tokenize(tweet) if ((w.lower() not in stop) and username_filter(w))]
        words = [lem.lemmatize(w) for w in words if len(w) > 2]
        corpus.append(words)
    return corpus

corpus = preprocess_tweets(tsa)
# corpus


# In[19]:


dic = gensim.corpora.Dictionary(corpus)
bow_corpus = [dic.doc2bow(doc) for doc in corpus]


# In[20]:


lda_model = gensim.models.LdaMulticore(bow_corpus, num_topics = 4, id2word = dic, passes = 10, workers = 2)
lda_model.show_topics()


# ### VISUALIZING RESULTS OF LDA

# In[21]:


# import pyldavis


# ### WORDCLOUD

# In[22]:


from wordcloud import WordCloud, STOPWORDS


# In[23]:


stopwords = set(STOPWORDS)

def show_wordcloud(data):
    wordcloud = WordCloud(
        background_color='white',
        stopwords=stopwords,
        max_words=100,
        max_font_size=30,
        scale=3,
        random_state=1)
   
    wordcloud=wordcloud.generate(str(data))

    fig = plt.figure(1, figsize=(12, 12))
    plt.axis('off')

    plt.imshow(wordcloud)
    plt.show()

show_wordcloud(corpus)


# In[ ]:




