# HandlerThread

## 简介

首先祭出前辈的文章

[Android多线程：手把手教你使用HandlerThread](https://www.jianshu.com/p/9c10beaa1c95)

[Android多线程：这是一份全面 & 详细的HandlerThread学习指南](https://www.jianshu.com/p/540f0c6c7bd1)

[Android多线程：这是一份详细的HandlerThread源码分析攻略](https://www.jianshu.com/p/4a8dc2f50ae6)

* 定义
  * 一个Android已封装好的轻量级异步类
* 作用
  * 实现多进程
    * 在工作线程中执行任务，耗时任务
  * 异步通信、消息传递
    * 实现工作线程&主线程（UI线程）之间的通信
    * 描述：将工作线程的执行结果传递给主线程，从而在主线程中执行相关的UI操作
* 优点
  * 方便实现异步通信
  * 即不需要使用任务。。。那个复杂组合
* 工作原理
  * 通过继承Thread类，快速创建一个带有Looper对象的新工作线程
  * 通过封装Handler类，快速创建Handler&与其他线程进行通信

## 具体使用 分5步

```java
// 步骤1：创建HandlerThread实例对象
// 传入参数 = 线程名字，作用 = 标记该线程
   HandlerThread mHandlerThread = new HandlerThread("handlerThread");

// 步骤2：启动线程
   mHandlerThread.start();

// 步骤3：创建工作线程Handler & 复写handleMessage（）
// 作用：关联HandlerThread的Looper对象、实现消息处理操作 & 与其他线程进行通信
// 注：消息处理操作（HandlerMessage（））的执行线程 = mHandlerThread所创建的工作线程中执行
  Handler workHandler = new Handler( handlerThread.getLooper() ) {
            @Override
            public boolean handleMessage(Message msg) {
                ...//消息处理
                return true;
            }
        });

// 步骤4：使用工作线程Handler向工作线程的消息队列发送消息
// 在工作线程中，当消息循环时取出对应消息 & 在工作线程执行相关操作
  // a. 定义要发送的消息
  Message msg = Message.obtain();
  msg.what = 2; //消息的标识
  msg.obj = "B"; // 消息的存放
  // b. 通过Handler发送消息到其绑定的消息队列
  workHandler.sendMessage(msg);

// 步骤5：结束线程，即停止线程的消息循环
  mHandlerThread.quit();
```

## 注意

### 内存泄漏

```cpp
In Android, Handler classes should be static or leaks might occur.
```

 [Android 内存泄露：详解 Handler 内存泄露的原因](https://www.jianshu.com/p/ed9e15eff47a)

### 连续发送消息

使用HandlerThread时只是开了一个工作线程，调用n次，只是把消息添加到消息队列中了

