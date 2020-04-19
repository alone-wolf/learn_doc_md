# 3.3 Handler 基础使用

## 简介

### 前言

* 在Android开发的多线程应用场景中，Handler机制十分常用

## 目录

1. 定义
2. 作用
3. 意义
4. 相关概念
5. 使用方法
6. 工作原理
7. 源码分析
8. 额外注意 内存泄漏
9. 总结

## 1.定义

一套Android消息传递机制

## 2. 作用

在多线程的应用场景中，将工作线程中需要更新的UI操作信息传递到UI主线程，从而实现工作线程对UI的更新处理，最终实现异步消息的处理

工作线程->(更新UI的操作信息)->Handler->(传递工作线程更新UI的操作信息)->主程(UI线程)->在主线程中更新UI

## 3.意义

* 多个线程保证并发更新UI的同时 保证线程安全
* 背景
  * 在Android开发中，为了UI操作是线程安全的，规定了只允许UI线程更新Activity里的UI组件
  * UI线程即主线程
* 冲突
  * 在实际开发中，存在多个线程并发操作UI组件的情况，导致UI操作的线程不安全
  * 故现在的需求为
    * 多个线程可并发操作UI组件
    * 保证线程安全
  * 解决方案
    * Handler消息传递机制
    * 即 工作线程需要更新时，通过Handler通知主线程，从而在主线程更新UI操作

## 4.相关概念

关于Handler异步通信机制中的相关概念：

| 概念                     | 定义                                               | 作用                                                         | 备注                                                         |
| ------------------------ | -------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 主线程 UI线程 MainThread | 当应用程序第一次启动时，会同时自动开启一条主线程   | 处理与ui相关的事件 如更新、操作等                            |                                                              |
| 子线程 工作线程          | 人为手动开启的线程                                 | 执行耗时操作 如网络请求、数据加载                            |                                                              |
| 消息 Message             | 线程间通讯的数据单元 即 Handler接受&处理的消息对象 | 存储需操作的通信信息                                         |                                                              |
| 消息队列 Message Queue   | 一种 数据结构 存储特点先进先出                     | 存储Handler发送过来的消息Message                             |                                                              |
| 处理者 Handler           | 主线程与子线程的通信媒介 线程消息的主要处理者      | 添加消息到队列 处理循环器分派过来的消息                      |                                                              |
| 循环器 Lopper            | 消息队列与处理者的通信媒介                         | 消息循环，即 消息获取（循环取出消息队列的消息）消息分发（将取出的消息发送给对应的处理者） | 每个线程只能拥有一个Looper，1个Looper可绑定多个线程的Handler，即多个线程可往1个Looper所持有的消息队列中发送消息提供了线程间通信的可能 |

## 5.使用方式

[Android：这是一份Handler消息传递机制 的使用教程](https://www.jianshu.com/p/e172a2d58905)

* Handler的使用方式因发送消息到消息队列的方式不同而不同

* 方式1 使用Handler.sendMessage()

  * 新建Handler子类

  ```java
  class mHandler extends Handler{
    @Override
    public void handleMessage(Message msg){
      // 需执行的UI操作
    }
  }
  
  // 在主线程中创建Handler实例
  private Handler mhandler = new mHandler();
  
  // 创建所需的消息对象
  Message msg = Message.obtain(); // 实例化消息对象
  msg.what = 1; // 消息标识
  msg.obj = "AA"; // 消息内容存放
  
  // 在工作线程中 通过Handler发送消息到消息队列中
  //可通过sendMessage()/post()
  //多线程可使用AsyncTask、继承Thread、实现Runnable
  mHandler.sendMessage(msg);
  
  // 开启工作线程（同时启动了Handler）
  ```

  * 匿名内部类

  ```java
  // 在主线程中通过匿名内部类 创建Handler对象
  private Handler mhandler = new Handler(){
    @Override
    public void handleMessage(Message msg){
      // 执行ui操作
    }
  };
  
  // 创建消息对象
  Message msg = Message.obtain(); // 实例化消息对象
  msg.what = 1; // 消息标识
  msg.obj = "AA"; // 存放消息内容
  
  // 在工作线程中 通过Handler发送消息到消息队列中
  // 多线程可以使用AsyncTask、继承Thread类、实现Runnable
  mHandler.sendMessage(msg);
  
  // 开启工作线程（同时启动了Handler）
  // 多线程采用AsyncTask、继承Thread类、实现Runnable
  
  ```

  

* 方式2 使用Handler.post()

  ```java
  // 在主线程中创建Handler实例
  private Handler mhandler = new mHandler();
  
  // 在工作线程中 发送消息到消息队列中&指定操作UI内容
  // 需传入一个Runnable对象
  mHandler.post(new Runnable){
    @Override
    public void run(){
      // needed UI operation
    }
  }
  
  // step 3 start work thread (open the Handler at the main time)
  ```


注：

1. 由于Handler的作用=将工作线程需操作UI的消息传递到主线程，使得主线程可根据工作线程的需求更新UI，从而避免线程操作不安全的问题

## 6. 工作原理

[Android Handler：图文解析 Handler通信机制 的工作原理](https://www.jianshu.com/p/f0b23ee5a922)

* 理解Handler机制的工作流程，能更好的帮助我们使用Handler&理解其内部流程

* Handler机制的工作流程主要包括四个步骤

  * 异步通信准备
  * 消息发送
  * 消息循环
  * 消息处理

  | 步骤         | 具体描述                                                     | 备注                                                         |
  | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | 异步通信准备 | 在主线程中创建 处理器对象（Looper） 消息队列（Message Queue） Handler对象 | Looper Message Queue均属于主线程，创建消息队列后，Looper自动进入消息循环，此时Handler自动绑定了主线程的Looper、Message Queue |
  | 消息入队     | 工作线程通过Handler发送消息到消息队列中                      | 该消息内容就是工作线程对UI的操作                             |
  | 消息循环     | 消息出队：Looper循环取出消息队列中的消息 消息分发：Looper将取出的消息发送给创建该消息的处理者 | 在消息的循环过程中，若消息队列为空，则线程阻塞               |
  | 消息处理     | 处理者（Handler）接收Looper发送过来的消息，处理者根据消息进行UI操作 |                                                              |



### 特别注意

线程Thread 循环器Looper 处理者Handler之间的对应关系如下

* 1个Thread只能绑定1个Looper，但可以有多个Handler
* 1个Looper可绑定多个Handler
* 1个Handler只能绑定一个Looper

## 特别注意 内存泄漏

[Android 内存泄露：详解 Handler 内存泄露的原因](https://www.jianshu.com/p/ed9e15eff47a)

