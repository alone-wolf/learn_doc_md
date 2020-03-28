# 多线程

### 祭出前辈的博客

[这是一份全面 & 详细的Android多线程知识总结指南](https://juejin.im/post/5d12c1c66fb9a07ee30e2821)

### 大纲

* 多线程基础知识
* Android 多线程实现方式
* 基础使用
  * 继承Thread类
  * 实现Runnable接口
  * Handler
* 复合使用
  * AsyncTask
  * HandlerThread
  * IntentService
* 高级使用
  * 线程池 ThreadPool
* 对比
* 其他
  * 线程同步 Synchronized
  * 线程变量 ThreadLocal
* 总结

### 1. 多线程基础知识

祭出前辈分享的知识汇总
[Android多线程：你必须要了解的多线程基础知识汇总](https://www.jianshu.com/p/7a8cb20cfd80)

on the way

### 2. Android 多线程实现方式

* 基础使用
  * 继承Thread类
  * 实现Runnable接口
  * Handler
* 复合使用
  * AsyncTask
  * HandlerThread
  * IntentService
* 高级使用
  * 线程池 ThreadPool

### 3. 基础使用

#### 3.1 继承Thread类

* 定义
  * Thread类 = java中实现多线程的具体类
  * 封装了所需的线程操作
* 作用
  * 实现多线程
* 特点
  * 优点
    * 实现简单
      * 只要继承了Thread类 & 复写run即可实现多线程操作
  * 缺点
    * 局限性大
      * 必须继承Thread类
      * java规定是单继承
      * 即不能再继承其他类
    * 不适合资源共享
      * 1个线程 = 1个实例对象
      * 相对独立，无法进行资源共享
    * 消耗资源
      * Thread线程 = 一次性消费品
      * 1个线程 = 1个耗时任务
        * 执行完成任务线程会被自动销毁
        * 有100个耗时任务必须开100个进程
      * 多次创建销毁 十分耗费系统资源

##### 具体使用

[Android多线程：继承Thread类 使用解析](https://www.jianshu.com/p/834f336855c4)

使用步骤：创建线程类的子类，复写run方法，实例化线程对象，通过线程对象控制线程状态（运行 睡眠 挂起等），结束

java

```java
class MyThread extends Thread{
	@Override
	public void run(){}
}
MyThread mt=new MyThread(“线程名称”);
mt.start();
```

简便实用：java

```java
new Thread("name of thread"){
	@Override
	public void run(){
	// con
	}
}.start();
```

两种方法对比

| 方式     | 优点                   | 缺点                       | 应用场景                   |
| -------- | ---------------------- | -------------------------- | -------------------------- |
| 常规方式 | 创建的线程类对象可复用 | 使用复杂 代码量大          | 需复用线程类 or 线程对象   |
| 匿名类   | 使用简洁               | 创建的线程类 对象 不可复用 | 不需复用线程类 or 线程对象 |

与 实现Runnable接口 对比

在Java中，继承Thread类和实现Runnable接口是实现多线程最常见的两种方法

| 区别       | 继承Thread类                               | 实现Runnable接口                         |
| ---------- | ------------------------------------------ | ---------------------------------------- |
| 应用场景   | 各线程独立 分别完成各自任务                | 各线程协作完成 共享资源                  |
| 使用复杂度 | 复杂 代码量多                              | 简单 代码量少                            |
| 局限性     | 局限性高 必须继承Thread类 受制于java单继承 | 局限性低 不需要继承类 避免了单继承的局限 |

使用建议：根据应用场景选择不同的多线程实现方式，优先使用Runnable接口

注：若只想要重写run方法，而不重写其他Thread方法，则应该使用Runnable接口

#### 3.2 实现Runnable接口

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

##### 具体使用

[Android多线程：实现Runnable接口 使用解析（含实例教程）](https://www.jianshu.com/p/95b186fbf192)

使用过程：

1. 创建线程辅助类（实现Runnable接口）
2. 复写run方法（定义线程行为）
3. 创建线程辅助对象（实例化线程辅助对象）
4. 创建线程对象（实例化线程Thread类 创建时传入线程辅助类对象）
5. 通过线程对象控制线程的状态（运行 睡眠 刮起等）

java代码

```java
class MyThread implements Runnable{
    @Override
    public void run(){}
}
MyThread mt=new MyThread();
Thread td=new Thread(mt);
td.start();
```

简单使用 匿名类

```java
Runnable mt = new Runnable() {
  @Override
  public void run() {}
};
Thread mt1 = new Thread(mt, "窗口1");
mt1.start();
```

区别

| 方式     | 优点                                                | 缺点                         | 应用场景           |
| -------- | --------------------------------------------------- | ---------------------------- | ------------------ |
| 常规方式 | 功能扩展性好 创建的线程子类可以定义更多的方法去使用 | 使用复杂 代码量大            | 需扩展多线程功能   |
| 匿名类   | 使用简洁                                            | 功能扩展性差 只能实现run方法 | 无需扩展多线程功能 |

