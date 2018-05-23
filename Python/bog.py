from urllib.request import urlopen
bog=urlopen("http://www.bilibili.com/")
from bs4 import BeautifulSoup
obj=BeautifulSoup(bog)
pics=obj.findAll('img')
import re
pattern = re.compile(r'"//.+"\s')
img=[]
for u in pics:
    s=str(u)
    if(pattern.search(s)):
        img.append(re.findall(pattern,s))
for p in img:
    print(p)