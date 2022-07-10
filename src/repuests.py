import requests, json

def main():
    sendRequest('29.00Fresh air.')

def sendRequest(message):
    temp='今の室温は'+message[0:4]+'度です。'
    air=message[5:]
    if(air=='Fresh air.'):
        airMessage='綺麗な空気です。'
    elif(air=='Low pollution!'):
        airMessage='まあまあ綺麗です。'
    elif(air=='High pollution!'):
        airMessage='ちょっと汚れてます、空気を入れ替えましょう！'
    elif(air=='High pollution! Force signal active'):
        airMessage='今すぐ空気を入れ替えましょう！'

    json_open = open('discord_url.json', 'r')
    json_load = json.load(json_open)

    webhook_url  = json_load['discord']['url']
    main_content = {
    'username': '空気読めるくん',
    'content': temp+'\r'+airMessage,
    #'avatar_url':'icon.png', Google driveにいれてURLで参照させればいけるっぽい
    'avatar_url':'https://1.bp.blogspot.com/-hAJbBMDcE48/XyZ_RM5PFxI/AAAAAAABaZ8/YJEVr2-vgKYAFKmOJezrcNin2QKNbjLSQCNcBGAsYHQ/s1600/kandume_kuuki_close.png',
        }
    headers      = {'Content-Type': 'application/json'}

    response     = requests.post(webhook_url, json.dumps(main_content), headers=headers)
    print('送信しました！');

if __name__ == "__main__":
    main()