# android Activity Launch Mode

* standard 创建一个新实例
        
        Activity 由任务栈管理，每启动一个Act，就会被放入栈中，返回键就从栈顶移除一个
    
* singleTop task栈顶复用模式

* singleTask task栈内复用模式

* singleInstance 全局单例模式



### kotlin

```kotlin
val intent = Intent(context,RecvActivity::class.java)
startActivity(intent)
```

```kotlin
val intent = Intent(context,RecvActivity::class.java)
intent.putExtra("text","value")
startActivity(intent)
```

