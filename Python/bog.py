import re
from urllib.request import urlopen

from bs4 import BeautifulSoup

bog=urlopen("http://www.bilibili.com/")
obj=BeautifulSoup(bog,"html5lib")
pics=obj.findAll('img')
pattern = re.compile(r'//.+@')
img=[]
for u in pics:
    s=str(u)
    if(pattern.search(s)):
        p=re.findall(pattern,s)
        img.append(p)
for p in img:
    print(p)
