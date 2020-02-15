# go for

### eg:

    1. 标准写法

    for 表达式1; 表达式2; 表达式3{

    }

    func main() {
	    for i:=0;i<100;i++{
		    print(strconv.Itoa(i)+" ")
	    }
    }

    ||

    2. 省略表达式1 3
    不同点即为，i变量的作用域不同

    func main() {
	    i := 1
        for i < 100 {
            print(strconv.Itoa(i) + " ")
            i++
        }
    }

***

    3.  省略所有表达式
    for{
        print(1)
    }

    ||

    相当于其他语言中的
    while(true){

    }

***

    4. 
    省略表达式1 表达式1要写在循环外面
    省略表达式2 相当于条件永为true
    省略表达式3 操作要么没有 要么放在括号里



