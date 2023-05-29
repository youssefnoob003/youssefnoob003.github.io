import urllib.request
from bs4 import BeautifulSoup
import re
link = input("enter- ")

source = urllib.request.urlopen(link)
soup = BeautifulSoup(source, "lxml")

tags = soup.find_all('li', class_='clearfix job-bx wht-shd-bx')

for tag in tags:
    if 'Posted few days ago' in str(tag('span')):
        print(tag.find('h3', class_='joblist-comp-name').text.strip())
        print(tag.find('span', class_='srp-skills').text.strip())
    print("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\")

x = input("print the job company or id for the description: ")
for tag in tags:
    if tag.find('h3', class_='joblist-comp-name').text.strip() == x:
        desc = urllib.request.urlopen(tag.h2.a['href'])
        sdesc = BeautifulSoup(desc, 'lxml')
        res = sdesc('div', class_="jd-desc job-description-main")
        for line in res:
            print(line.text)
