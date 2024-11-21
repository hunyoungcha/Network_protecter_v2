import json
import sys

with open(sys.argv[1]) as f:
    jsonData = json.load(f)

ips=set()

for idx,data in enumerate(jsonData):
    url = data['url']
    details = data['details']

    for detail in details:
        ips.add(detail['ip_address'])

print(ips)