#!/usr/bin/env python3

import requests
import webbrowser
import re
import json

key = 'Your virustotal API key here'


def file_scan():
    virustotal_url = 'https://www.virustotal.com/vtapi/v2/file/scan'
    path = input("Please enter the path of the file you wish to scan: ")
    file = {'file': ("myfile", open(path, 'rb'))}

    params = {'apikey': key}
    response = requests.post(virustotal_url, files=file, data=params)
    data = response.json()
    site = data['permalink']
    webbrowser.open(site)


def url_scan():
    virustotal_url = 'https://www.virustotal.com/vtapi/v2/url/scan'
    scan_url = input("Please enter the URL to scan: ")
    good_url = False

    while not good_url:
        # RegEx to make sure url starts with http or www
        if re.match('(^(http:))', scan_url) or re.match('(^(www.))', scan_url):
            good_url = True
        else:
            print("Enter url starting with http or www\n")
            scan_url = input("Please enter the URL to scan: ")

    # Send request to virustotal, open up link that has virustotal report on url
    params = {'apikey': key, 'url': scan_url}
    response = requests.post(virustotal_url, data=params)
    data = response.json()
    site = data['permalink']
    webbrowser.open(site)


def ip_scan():
    virustotal_url = 'https://www.virustotal.com/vtapi/v2/ip-address/report'
    ip = input("Please enter a IP address: ")

    params = {'apikey': key, 'ip': ip}
    response = requests.get(virustotal_url, params=params)
    print(response.status_code)
    print(response.json())
    #data = response.json()
    #site = json.dump(data,indent=2,sort_keys=True)
    #print(site)



print("""Welcome to VirusTotal API. Please enter the number of what you would like to scan.
-------------------------------------------------------------------------------------------
1. Scan a file \n
2. Scan a URL \n
3. Scan a IP address, domain or hash
-------------------------------------------------------------------------------------------
""")

selection = input("Please enter the instruction number: ")

goodInput = False
while not goodInput:
    if selection == "1":
        file_scan()
        goodInput = True
    elif selection == "2":
        url_scan()
        goodInput = True
    elif selection == "3":
        ip_scan()
        goodInput = True
    else:
        print("\nIncorrect input... Please enter a number ")
        selection = input("Please enter the instruction number: ")
