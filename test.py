from functools import wraps

def check_access_auth():
    @wraps(func)
    def wrapper(*args, **kwargs):
        token = request.header.to_dict()
        print(token)
        return func(*args, **kwargs)
    return wrapper