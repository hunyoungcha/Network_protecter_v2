import json
import sys
import sqlite3

#json파일을 입력 받기
try:
    filename = sys.argv[1]
except:
    print("json 파일 입력 필요")
    exit(1)


#입력 받은 json파일 열기
with open(filename) as f:
    jsonData = json.load(f)

#ip가 저장될 집합 (중복x)
ips=set()


#ip 데이터 파싱 후 저장
for data in jsonData:
    details = data['details']

    for detail in details:
        ips.add(detail['ip_address'])

# 튜플 리스트로 변환
# excutemany를 사용할 것이기 때문
# excutemany는 리스트 안에 저장된 튜플의 형태만 사용 가능
# ip 뒤에 ,를 찍는 이유는 괄호 안에 값이 하나일 경우 튜플이 아닌 문자열로 인식하기 때문
ip_data = [(ip,) for ip in ips]


#DB 연동
database = 'network_protecter.db'
conn = sqlite3.connect(database)
cursor = conn.cursor()

cursor.executemany("INSERT OR IGNORE INTO phishing (ip) VALUES (?)", ip_data)

conn.commit()
conn.close()