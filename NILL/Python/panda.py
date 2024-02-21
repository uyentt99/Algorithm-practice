import pandas as pd
#--------------------CSV file-----------------------------
#read
df = pd.read_csv("Cust_Segmentation.csv")
#get head
df.head()
#describe
df.describe()
#get values for row,column
X = df.values[:,1:]
#or
X = df[df.columns[:11]].values
#get som column base on column name
cdf = df[['a','b','c']]
#count values
df['custcat'].value_counts()