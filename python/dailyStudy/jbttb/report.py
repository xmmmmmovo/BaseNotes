import httpx
from pprint import pprint

data = {
    'IsContactFever': False,
    'IsSymptoms': None,
    'IsSuspected': None,
    'IsConfirmed': None,
    'IsContactSuspected': False,
    'IsContactConfirmed': False,
    'IsContactEpidemic': None,
    'IsContactRisk': False,
    'PersonnelTypeID': 6,
    'HolderID': None,
    'Holder': None,
    'province1': 37,
    'city1': ,
    'district1': 370102,
    'PositionID': 9,
    'province2': 000000,
    'city2': ,
    'district2': 000000,
    'Temperature': 36.5,
    'PhysicalConditionID': 1,
    'iscontactfever': False,
    'iscontactsuspected': False,
    'iscontactconfirmed': False,
    'iscontactrisk': False,
    'ReturnTime1': None,
    'province5': 000000,
    'city5': 000000,
    'district5': 000000,
    'ReturnTool': '自驾',
    'ReturnToolRemark': None,
    'ReturnRemark': None,
    'ReturnTime2': None,
    'Station': '其他'
}

headers = {
    'cookie': '__RequestVerificationToken=QdFrFAmJubjcRH-SchCXWdra-uMHMEAbOg1lPzXpmtmtRtJBGVRV8UxP-7pKNzszjxgNbAN1Cz7TNSOkvwaynNx6AFmoYBwGrGsDuq1DQP81; ASP.NET_SessionId=005pa4lonab0aqjifl0yggjg; .ASPXFORMSAUTHYZY=08551157E69B933073A3F69FDE871618874A86A500CC87F3C68F44B4A98F8B37B8BEF1A97EE0899727C23EC23EB6A10244751FFC32C5CF3627B57FD9289E30A2139C7398E85592CFE4C513C9C5B962BC0BF369026E306EEF3DFD04C8661B529DB46899D053F0BA884D84BDCC900C33C1',
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.129 Safari/537.36'
}

r = httpx.post(
    "http://39.98.190.134:81/Report",
    data=data,
    headers=headers
)

pprint(r.text)
