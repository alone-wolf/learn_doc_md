# ThreadPool

## 简介

* 定义
	* 一块缓存了一定数量线程的区域
* 作用
	* 复用线程
	* 管理线程
		* 如统一分配 调优 监控
		* 又如 控制线程池的最大并发数
* 优点
	* 降低 因线程创建销毁所带来的性能开销
		* 重用 换存在线程池的线程
	* 提高 线程响应速度 执行效率
		* 重用线程 = 不需创建线程 马上就可执行
		* 管理线程 = 优化线程的执行顺序
			* 避免大量线程间因互相抢占系统资源而导致阻塞现象
	* 提高 对线程的管理度
* 注
	* 传统的多线程方式的问题
		* 每次新建/销毁线程对象消耗资源、响应速度慢
		* 线程缺乏统一管理，容易出现 阻塞情况

## 具体使用&工作原理

[Android多线程：线程池ThreadPool 全面解析](https://www.jianshu.com/p/0e4a5e70bf0e)

### 核心参数

| 参数            | 意义                            | 说明                                                         |
| --------------- | ------------------------------- | ------------------------------------------------------------ |
| corePoolSize    | 核心线程数                      | 默认情况下，核心线程一直存活                                 |
| maximumPoolSize | 线程池所能容纳的最大线程数      | 当活动线程数到达该值后，后续的新任务会阻塞                   |
| keepAliveTime   | 非核心线程 闲置超时时间         | 超过该时常，非核心线程就会被回收，当allowCoreThreadTimeout时，该值同样作用于核心线程 |
| unit            | 指定keepAliveTime参数的时间单位 | 常用（毫秒）TimeUnit.MILLISECONDS,(秒，分)                   |
| workQueue       | 任务队列                        | 通过线程池的excute方法提交的Runnable对象将存储在该参数中     |
| threadFactory   | 线程工厂，是一个接口            | 作用：为线程池创建新线程，，具体使用，Thread new Thread(Runnable r); |

* 上述6个参数的配置 决定了线程池的功能，具体设置时机 = 创建线程池类对象时 传入
	* ThreadPoolExcutor类 = 线程池的真正实现类
	* 开发者可根据不同需求 配置核心 参数 从而实现自定义线程池

```java
// 创建线程池对象如下
// 通过 构造方法 配置核心参数
Executor executor = new ThreadPoolExecutor(
  CORE_POOL_SIZE,
  MAXIMUM_POOL_SIZE,
  KEEP_ALIVE,
  TimeUnit.SECONDS,
  sPoolWorkQueue,
  sThreadFactory
);

// 构造函数源码分析
    public ThreadPoolExecutor (int corePoolSize,
                               int maximumPoolSize,
                               long keepAliveTime,
                               TimeUnit unit,
                               BlockingQueue<Runnable workQueue>,
                               ThreadFactory threadFactory)
```

### 使用流程

```java
// 1. 创建线程池
   // 创建时，通过配置线程池的参数，从而实现自己所需的线程池
   Executor threadPool = new ThreadPoolExecutor(
                                              CORE_POOL_SIZE,
                                              MAXIMUM_POOL_SIZE,
                                              KEEP_ALIVE,
                                              TimeUnit.SECONDS,
                                              sPoolWorkQueue,
                                              sThreadFactory
                                              );
    // 注：在Java中，已内置4种常见线程池，下面会详细说明

// 2. 向线程池提交任务：execute（）
    // 说明：传入 Runnable对象
       threadPool.execute(new Runnable() {
            @Override
            public void run() {
                ... // 线程执行任务
            }
        });

// 3. 关闭线程池shutdown() 
  threadPool.shutdown();
  
  // 关闭线程的原理
  // a. 遍历线程池中的所有工作线程
  // b. 逐个调用线程的interrupt（）中断线程（注：无法响应中断的任务可能永远无法终止）

  // 也可调用shutdownNow（）关闭线程：threadPool.shutdownNow（）
  // 二者区别：
  // shutdown：设置 线程池的状态 为 SHUTDOWN，然后中断所有没有正在执行任务的线程
  // shutdownNow：设置 线程池的状态 为 STOP，然后尝试停止所有的正在执行或暂停任务的线程，并返回等待执行任务的列表
  // 使用建议：一般调用shutdown（）关闭线程池；若任务不一定要执行完，则调用shutdownNow（）
```

### 常见的4类功能线程池

根据参数的不同配置

* 定长线程池 FixedThreadPool
* 定时线程池 ScheduledThreadPool
* 可缓存线程池 CachedThreadPool
* 单线程化线程池 SingleThreadExecutor

对于上述4类线程池，java已根据应用场景配置好核心参数



#### 1. 定长线程池FixedThreadPool

* 特点 只有核心线程&不会被回收、线程数量固定、任务队列大小无限制（超出最大值的任务在队列中等待）
* 应用场景 控制线程最大并发数
* 具体使用 通过 Executors.newFixedThreadPool() 创建
* 示例

```java
// 1. 创建定长线程池对象 & 设置线程池线程数量固定为3
ExecutorService fixedThreadPool = Executors.newFixedThreadPool(3);

// 2. 创建好Runnable类线程对象 & 需执行的任务
Runnable task =new Runnable(){
  public void run(){
    System.out.println("执行任务啦");
     }
    };
        
// 3. 向线程池提交任务：execute（）
fixedThreadPool.execute(task);
        
// 4. 关闭线程池
fixedThreadPool.shutdown();
```

#### 2. 定时线程池ScheduledThreadPool

* 特点 核心线程数固定、非核心线程数量无限制（限制马上收回）
* 应用场景 执行定时/周期性任务
* 使用 通过Executors.newScheduledThreadPool()创建
* 示例

```java
// 1. 创建 定时线程池对象 & 设置线程池线程数量固定为5
ScheduledExecutorService scheduledThreadPool = Executors.newScheduledThreadPool(5);

// 2. 创建好Runnable类线程对象 & 需执行的任务
Runnable task =new Runnable(){
       public void run(){
              System.out.println("执行任务啦");
          }
    };
// 3. 向线程池提交任务：schedule（）
scheduledThreadPool.schedule(task, 1, TimeUnit.SECONDS); // 延迟1s后执行任务
scheduledThreadPool.scheduleAtFixedRate(task,10,1000,TimeUnit.MILLISECONDS);// 延迟10ms后、每隔1000ms执行任务

// 4. 关闭线程池
scheduledThreadPool.shutdown();
```

#### 3. 可缓存线程池CachedThreadPool

* 特点 只有非核心线程、线程数量不固定，可无限多、灵活回收空闲线程，具备超时机制，全部回收时几乎不占系统资源、无线程可用时新建线程
* 任何任务到来都无需等待，立即执行
* 应用场景 执行量大、耗时少的线程任务
* 使用 通过Executors.newCachedThreadPool()创建
* 示例

```java
// 1. 创建可缓存线程池对象
ExecutorService cachedThreadPool = Executors.newCachedThreadPool();

// 2. 创建好Runnable类线程对象 & 需执行的任务
Runnable task =new Runnable(){
  public void run(){
        System.out.println("执行任务啦");
            }
    };

// 3. 向线程池提交任务：execute（）
cachedThreadPool.execute(task);

// 4. 关闭线程池
cachedThreadPool.shutdown();

//当执行第二个任务时第一个任务已经完成
//那么会复用执行第一个任务的线程，而不用每次新建线程。
```

#### 4. 单线程化线程池SingleThreadExecutor

* 特点 只有一个核心线程，保证所有任务按照指定顺序在一个线程中执行，不需要处理线程同步的问题
* 应用场景 不适合并发单可能引起IO阻塞性及影响UI线程响应的操作，如数据库操作，文件操作等
* 使用 通过Executors.newSingleThreadExecutor()创建
* 示例

```java
// 1. 创建单线程化线程池
ExecutorService singleThreadExecutor = Executors.newSingleThreadExecutor();

// 2. 创建好Runnable类线程对象 & 需执行的任务
Runnable task =new Runnable(){
  public void run(){
        System.out.println("执行任务啦");
            }
    };

// 3. 向线程池提交任务：execute（）
singleThreadExecutor.execute(task);

// 4. 关闭线程池
singleThreadExecutor.shutdown();
```

#### 5. 常见线程池 总结 对比

| 类型           | 池内 线程类型   | 池内 线程数量                  | 处理特点                                                     | 应用场景                                                     |
| -------------- | --------------- | ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 定长线程池     | 核心线程        | 固定                           | 核心线程处于空闲状态时也不会被回收，除非线程被关闭，当所有线程都处于活动状态时，新的任务都会处于等待状态，直到有线程空闲出来，，任务队列大小无限制，超出的线程任务会在队列中等待 | 控制线程最大并发数                                           |
| 定时。。。     | 核心&非核心线程 | 核心线 固定，非核心线程 无限制 | 当非核心线程闲置h时，会被立即回收                            | 执行定时/周期任务                                            |
| 可缓存。。。   | 非核心线程      | 不固定，可无限大               | 优先利用闲置的线程处理新任务，无线程可用时新建线程，灵活回收空闲线程 | 执行数量多耗时少的任务                                       |
| 单线程化。。。 | 核心线程        | 1个                            | 保证所有任务按照指定的顺序在一个线程中执行，不需要处理线程同步的问题 | 单线程，不适合并发但可能引起IO阻塞性及影响UI线程响应的操作，如数据库操作等 |

