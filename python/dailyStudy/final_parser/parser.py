import json

write_file = open("./jike.txt", "a+")

with open("./jike.json") as f:
    dict = json.load(f)
    rows = dict["rows"]
    print(len(rows))
    for r in rows:
        msg = ""
        msg += f"{r['topicName']} "
        msg += f"{r['baseUserInfo']['userName']} {r['baseUserInfo'].get('technicalId')} \n"
        msg += f"{r['id']}\n"
        msg += f"{r['isRenewal']} {r['topicPeopleType']} {r['topicSource']} {r['topicProperty']}  \n"
        msg += f"{r['requirement']} {r['synopsis']} \n\n"
        write_file.write(msg)
