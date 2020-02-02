# python3 lambda

    a = lambda x:x**2

    lambda used to create a function easily with one line,
    print(a) we will get a function fd
    <function <lambda> at somewhere>

    def a(x,y):
        return x**y

    ||

    a = lambda x,y:x**y
    

***

    x = ['a', 'b', 'c', 'd']
    y = [1, 2, 3, 4]
    a = lambda x,y:{x[i]:y[i] for i in range(len(x))}

    ||

    def a(x,y):
        return {x[i]:y[i] for i in range(len(x))}

    ||

    def a(x,y):
        newdict = {}
        for i in range(len(x)):
            newdict[x[i]]=y[i]
        return newdict

***

    

