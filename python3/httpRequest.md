# python3 http 请求

## 使用requests模块

    import requests
    
    r = requests.get(url)
    
    r = requests.get('http://url',params = {'a':'aaa'})
    
    r.status_code
    r.url
    r.text
    
    payload = {'username':'wolf'}
    r = requests.post(url,data=payload)

