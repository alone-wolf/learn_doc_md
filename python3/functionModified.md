# python3 @ 修饰

### 说明

    修饰符@的作用是为了现有的函数增加额外的功能
    常用于插入日志 性能测试 事务处理等

    创建函数修饰符的规则：
        修饰符是一个函数
        修饰取被修饰函数为参数
        修饰符返回一个新函数
        修饰符维护被维护函数的签名

### 被修饰函数不带参数

    def log(func):
        def warpper():
            print('log start')
            func()
            print('log stop)
        return wapper

    

    @log
    def test():
        print('test')

    test()

    运行结果:
    log start
    test
    log stop

### 使用functools模块提供的修改函数属性的方法wraps

    def log(func):
        def wrapper():
            print('log start)
            func()
            print('log stop)
        return wrapper

    @log
    def test1():
        print('test1')

    def test2():
        print('test2')

    print(test1.__name__)
    print(test2.__name__)

    运行结果：
    wrapper
    test2

    上述方法会改变函数的函数名称，可以使用functools模块提供的修改函数属性的方法wraps

    from functools import wraps

    def log(func):
        @wraps(func)
        def wrapper():
            print('log start')
            func()
            print('log stop')
        return wrapper

    @log
    def test1():
        print('test1')

    def test2():
        print('test2')

    print(test1.__name__)
    print(test2.__name__)

    运行结果：
    test1
    test2

### 被修饰函数待参数

    from functools import wraps

    def log(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            print('log start',func.__name__)
            ret = func(*args, **kwargs)
            print('log stop')
            return ret
        return wrapper

    @log
    def test1(s):
        print('test1',s)
        return s

    

    @log
    def test2(s1,s1):
        print('test2',s1,s2)
        return s1+s2

    test1('a')
    test2('b','cd')

    运行结果:
    log start test1
    test1 a
    log stop
    log start test2
    test2 b cd
    log stop

### 修饰符带参数 需要多一层包装

    from functools import wraps

    def log(arg):
        def _log(func):
            @wraps(func)
            def wrapper(*args,**kwargs):                    
            print('log start',func.__name__,arg)
                ret = func(*args,**kwargs)
                print('log stop')
                return ret
            return wrapper
        return _log

    @log('m1')
    def test1(s):
        print('test1',s)
        return s

    @log('m2')
    def test2(s,d):
        print('test2',s,d)
        return s+d

    test1('a')
    test2('b','c')

    运行结果：
    log start test1 m1
    test1 a
    log stop
    log start test2 m2
    test2 b c
    log stop

## END

    

