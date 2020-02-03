# python3 随机数

## 使用random模块

    import random

    def result(p, c):
        if (p - c) == -1 or (p - c) == 2:
            return 'p w'
        elif (p - c) == 1 or (p - c) == -2:
            return 'c w'
        else:
            return 'no w'

    if __name__ == '__main__':
        print(result(int(input('0石头 1剪刀 2布: ')) % 3, random.randint(0, 2)))

