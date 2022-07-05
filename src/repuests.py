import requests, json

json_open = open('discord_url.json', 'r')
json_load = json.load(json_open)

webhook_url  = json_load['test']['url']
main_content = {
    'username': 'かわいいねこ',
    'content': 'おはよう！',
    #'avatar_url':'icon.png', Google driveにいれてURLで参照させればいけるっぽい
    'avatar_url':'https://4.bp.blogspot.com/-SNILKxCoGxA/WMdTfmXnenI/AAAAAAABChM/HeJqR7MV9ZE2vXQFmdVeaZ3t6NxV6R9QwCLcB/s800/pet_nekotsugura.png',
    }
headers      = {'Content-Type': 'application/json'}

response     = requests.post(webhook_url, json.dumps(main_content), headers=headers)
print('送信しました！');
