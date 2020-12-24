import requests

headers = {
}

resp = requests.post("http://sxqfwl2015.6655.la:20002/CollegeThesis_dsj/student2Topic/toSelect", data={
    "id": "e2a0a938-884d-4776-9393-b4fc28ef2701"
})
print(resp.text)
