# go array 数组

* 基本类型
    - 整数
    - 浮点
    - 布尔
    - 字符串
* 符合类型
    - array
    - slice
    - map
    - struct
    - pointer
    - function
    - channel
    - ...

    

***

### 数组

1. 存储一组相同数据类型的数据结构
2. 语法
3. 通过下标访问
4. 长度和容量

***

    func main() {
        var arr1[2] int
        arr1[0] = 1
        arr1[1] = 2

        println(arr1[0])
    }

    func main() {
        var arr1[3] int
        arr1[0] = 1
        arr1[1] = 2

        println(arr1[0])
        println(len(arr1))// 数组的长度
        println(cap(arr1))// 数组的容量

        // len 容器中实际存储的数据量
        // cap 容器能够存储的数据量
        // 因为数组定长 长度和容量相等
    }

