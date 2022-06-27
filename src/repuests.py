import requests, json

json_open = open('discord_url.json', 'r')
json_load = json.load(json_open)

webhook_url  = json_load['discord']['url']
main_content = {
    'username': 'test',
    'content': 'ねむねむにゃんこ',
    # 'avatar_url':'icon.png', Google driveにいれてURLで参照させればいけるっぽい
    }
headers      = {'Content-Type': 'application/json'}

response     = requests.post(webhook_url, json.dumps(main_content), headers=headers)
print('送信しました！');
