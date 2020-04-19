# 3.2 实现Runnable接口 基础使用

## 简介

* 定义
  * 一个与多线程相关的抽象接口
  * 仅定义了一个run方法
* 作用
  * 实现多线程
* 优点
  * 适合资源共享
    * Runnable的代码可被多个线程（Thread实例）共享
    * 适合于多个线程处理同一资源的情况
  * 灵活
    * 一个类可以继承多个接口
    * 避免了继承Thread类方式导致的单继承局限性

## 具体使用

[Android多线程：实现Runnable接口 使用解析（含实例教程）](https://www.jianshu.com/p/95b186fbf192)

### 使用过程：

1. 创建线程辅助类（实现Runnable接口）
2. 复写run方法（定义线程行为）
3. 创建线程辅助对象（实例化线程辅助对象）
4. 创建线程对象（实例化线程Thread类 创建时传入线程辅助类对象）
5. 通过线程对象控制线程的状态（运行 睡眠 刮起等）

### 特别注意

* java中真正能创建新线程的只有Thread类对象
* 通过实现Runnable的方式，最终还是通过Thread类对象来创建进程
* 所以对于实现了Runnable接口的类成为辅助类
* Thread类才是真正的线程类

### java代码

```java
class MyThread implements Runnable{
    @Override
    public void run(){/*more*/}
}
MyThread mt=new MyThread();
Thread td=new Thread(mt);
td.start();
```

### 简单使用 匿名类

```java
Runnable mt = new Runnable() {
  @Override
  public void run() {}
};
Thread mt1 = new Thread(mt, "窗口1");
mt1.start();
```

## 区别

| 方式     | 优点                                                | 缺点                         | 应用场景           |
| -------- | --------------------------------------------------- | ---------------------------- | ------------------ |
| 常规方式 | 功能扩展性好 创建的线程子类可以定义更多的方法去使用 | 使用复杂 代码量大            | 需扩展多线程功能   |
| 匿名类   | 使用简洁                                            | 功能扩展性差 只能实现run方法 | 无需扩展多线程功能 |



