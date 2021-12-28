import json
a={
    "name":"dabao",
    "id":123
}
b=json.dumps(a)
f2=open("new.json",'w')
f2.write(b)
f2.close()