import json
import sys

with open(sys.argv[1]) as f:
    jsonData = json.load(f)


    for idx,data in enumerate(jsonData):
        try:
            print('num : ' , idx)
            print('url : ' + data['url'])
            print(data['details'][0]['ip_address'])
        except: 
            print('nothing')