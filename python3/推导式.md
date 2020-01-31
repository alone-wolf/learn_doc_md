# python3 推导式

## 列表推导式

    list = []
    for i in range(100)
        list.append(i)
    print(list)

    ||

    list = [i for i in range(100)]
    print(list)

### 带if的列表推导式

    创建0-100 偶数列表
    list = [i for i in range(0,100,2)]
    print(list)

    ||

    list = [i for i in range(100) if i % 2 == 0]
    print(list)

### 多个for循环实现列表推导式

    list = [(i,j) for i in range(2) for j in range(3)]
    print(list)

    运行结果：
    [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2)]

## 字典推导式

    用于快速合并两个列表为一个字典
    或者 提取字典中目标数据

    key: list1 = [i for i in range(1,5)]
    vaule: list2 = [i**2 for i in list1]

    dict = {i : i**2 for i in range(1,5)}

### 合并两个数组为字典

    list1 = ['name','age','gender']
    list2 = ['Tom',20,'male']

    dict = {list1[i] : list2[i] for i in range(len(list1))}

### 提取字典中的目标数据

    counts = {'MBP':100,'HP':200,'DELL':300}

    count = {key:val for key,val in counts.items() if val>=200}

## 集合推导式

    list = [1, 1, 2]
    set = {i**2 for i in list}
    集合会去重
    运行结果：
    {1， 4}

