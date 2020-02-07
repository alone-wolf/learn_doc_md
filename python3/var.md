# 引用

## int

    a = 1
    b = a

    print(b)  # 1
    print(id(a))  # 10914496
    print(id(b))  # 10914496

    a = 2
    print(id(b))  # 10914496
    print(id(a))  # 10914528

    上述说明 int 为不可变类型

## 列表

    aa = [1,2,3]
    bb = aa

    x = print(id(aa)) == print(id(bb))

    aa.append(16)

    print(id(aa)) == print(id(bb)) == x

# 可变类型 不可变类型

## 可变类型

    列表
    字典
    集合

## 不可变类型

    int
    float
    string
    元组

# 变量作用域

    全局变量：
        def fun_name():
            global a
            a = 10
            pass
    局部变量就是非全局的普通变量

# return

    函数返回值可以有多个
    aa, bb, cc = return a, b, c

