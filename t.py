from functools import wraps


def log(func):
    @wraps(func)
    def warpper(*args,**kwargs):
        print('log start')
        ret = func(*args, **kwargs)
        print('log stop')
        return ret
    return warpper


@log
def test():
    print('aaaaa')


if __name__ == '__main__':
    test()
