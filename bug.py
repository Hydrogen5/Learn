import re
import urllib.request
def getHtml(url):
    page=urllib.request.urlopen(url)
    html=page.read()
    return html
def getsImg(html):
    reg=r'src="(.+?\.jpg)" .'
    imgre=re.compile(reg)
    imglist=re.findall(imgre,html)
    x=0
    for imgurl in imglist:
        urllib.request.urlretrieve(imgurl,'%s.jpg'%x)
        x+=1
html=getHtml("https://weibo.com/p/1005056180475384/home?from=page_100505_profile&wvr=6&mod=data&is_hot=1#_rnd1525007531050")
html = html.decode('GBK')
print(getsImg(html))
