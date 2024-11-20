import json

with open('./online-valid.json') as f:
    data = json.load(f)


print(data[1])