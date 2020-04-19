# AsyncTask

## 简介

* 定义
  * 一个Android已封装好的轻量级异步类
  * 属于抽象类 即使用时需要实现子类
* 作用
  * 实现多进程
    * 在工作线程中执行任务 如耗时任务
  * 异步通信、消息传递
    * 实现工作线程&主线程（UI线程）之间的通信
* 优点
  * 方便实现异步通信
    * 不需要使用“任务线程（如继承Thread类）+Handler的复杂组合”
  * 节省资源
    * 内部采用线程池的缓存线程+复用线程，避免了频繁创建&销毁线程所带来的系统资源开销

## 具体使用

[Android 多线程：手把手教你使用AsyncTask](https://www.jianshu.com/p/ee1342fcf5e7)

### 1 定义

* 一个Android已封装好的轻量级异步类
* 抽象类，使用时需实现子类

```cpp
public abstract class AsyncTask<Params, Progress, Result> { 
 ... 
 }
```

### 2 作用

1. 实现多线程 在工作线程中执行任务 如耗时任务
2. 异步通信、消息传递
   * 实现工作线程&主线程（UI线程）之间的通讯，即将工作线程的执行结果传递给主线程，从而在主线程中执行相关的UI操作
3. 从而保证线程安全

### 3 优点

* 方便异步通信
  * 不需使用“任务线程（如继承Thread类）+Handler”的复杂组合
* 节省资源
  * 采用线程池的缓存线程+复用线程，避免了频繁创建&销毁线程所带来的系统资源开销

### 4 类&方法介绍

#### 4.1 类定义

```cpp
public abstract class AsyncTask<Params, Progress, Result> { 
 ... 
}

// 类中参数为3种泛型类型
// 整体作用：控制AsyncTask子类执行线程任务时各个阶段的返回类型
// 具体说明：
    // a. Params：开始异步任务执行时传入的参数类型，对应excute（）中传递的参数
    // b. Progress：异步任务执行过程中，返回下载进度值的类型
    // c. Result：异步任务执行完成后，返回的结果类型，与doInBackground()的返回值类型保持一致
// 注：
    // a. 使用时并不是所有类型都被使用
    // b. 若无被使用，可用java.lang.Void类型代替
    // c. 若有不同业务，需额外再写1个AsyncTask的子类
```

#### 4.2 核心方法

| 核心方法                          | 作用                                                         | 调用时刻                                                     |                             备注                             |
| --------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | :----------------------------------------------------------: |
| excute(Params... params)          | 触发执行异步线程任务                                         | 手动调用                                                     |                必须在主线程调用，运行在主线程                |
| onPreExcute()                     | 执行线程任务前的操作，非必须                                 | 执行线程任务前自动调用                                       |          用于界面的初始化操作，如显示进度条的对话框          |
| doInBackground(Params... params)  | 接收输入参数，执行任务中的耗时操作，返回线程任务执行的结果，，必须项 | 执行线程任务时自动调用                                       | 不能修改UI组件的信息，执行过程中可调用publicProgress()更新进度信息 |
| onProgressUpdate(Progress values) | 在主线程显示线程任务执行的进度，非必须                       | 调用publicProgress(Progress... values)时自动调用             |                              /                               |
| onPostExcute(Result result)       | 接收线程任务执行结果，将执行结果显示到UI组件，，必须项       | 线程任务结束时自动调用                                       |                              /                               |
| onCancled()                       | 将异步任务设置为：取消状态，并不是真正的取消任务             | 异步任务被取消时即自动调用，需在doInBackground()中判断终止任务 |          该方法被调用时，onPostExcute()就不会被调用          |

方法执行顺序

|         类型         | 具体执行顺序                                                 |
| :------------------: | :----------------------------------------------------------- |
|       基础使用       | 手动调用excute-onPreExcute-doInBackGround-onPostExcute       |
|       显示进度       | 手动调用excute-onPreExcute-doInBackground-publicProgress-onPostExcute-onProgressUpdate |
| 执行线程任务时需终止 | 手动调用excute-onPreExcute-doInBackground-onCancled          |

## 5 使用步骤

AsyncTask的使用步骤有3

1. 创建其子类&根据需求实现核心方法
2. 创建其子类的实例对象（即任务实例）
3. 手动调用excute从而执行异步线程任务

具体介绍

```java
/**
  * 步骤1：创建AsyncTask子类
  * 注： 
  *   a. 继承AsyncTask类
  *   b. 为3个泛型参数指定类型；若不使用，可用java.lang.Void类型代替
  *   c. 根据需求，在AsyncTask子类内实现核心方法
  */

  private class MyTask extends AsyncTask<Params, Progress, Result> {

        ....

      // 方法1：onPreExecute（）
      // 作用：执行 线程任务前的操作
      // 注：根据需求复写
      @Override
      protected void onPreExecute() {
           ...
        }

      // 方法2：doInBackground（）
      // 作用：接收输入参数、执行任务中的耗时操作、返回 线程任务执行的结果
      // 注：必须复写，从而自定义线程任务
      @Override
      protected String doInBackground(String... params) {

            ...// 自定义的线程任务

            // 可调用publishProgress（）显示进度, 之后将执行onProgressUpdate（）
             publishProgress(count);
              
         }

      // 方法3：onProgressUpdate（）
      // 作用：在主线程 显示线程任务执行的进度
      // 注：根据需求复写
      @Override
      protected void onProgressUpdate(Integer... progresses) {
            ...

        }

      // 方法4：onPostExecute（）
      // 作用：接收线程任务执行结果、将执行结果显示到UI组件
      // 注：必须复写，从而自定义UI操作
      @Override
      protected void onPostExecute(String result) {

         ...// UI操作

        }

      // 方法5：onCancelled()
      // 作用：将异步任务设置为：取消状态
      @Override
        protected void onCancelled() {
        ...
        }
  }

/**
  * 步骤2：创建AsyncTask子类的实例对象（即 任务实例）
  * 注：AsyncTask子类的实例必须在UI线程中创建
  */
  MyTask mTask = new MyTask();

/**
  * 步骤3：手动调用execute(Params... params) 从而执行异步线程任务
  * 注：
  *    a. 必须在UI线程中调用
  *    b. 同一个AsyncTask实例对象只能执行1次，若执行第2次将会抛出异常
  *    c. 执行任务中，系统会自动调用AsyncTask的一系列方法：onPreExecute() 、doInBackground()、onProgressUpdate() 、onPostExecute() 
  *    d. 不能手动调用上述方法
  */
  mTask.execute()；
```

## 6 实例

见顶部链接

## 7 使用注意

### 7.1 关于生命周期

* 结论
  * AsyncTask不与任何组件绑定生命周期
* 使用建议
  * 在Activity或Fragment中使用AsyncTask时，最好在A/F的onFestory()中调用cancel(boolean);

### 7.2 关于内存泄漏

* 结论
  * 若AsyncTask被声明为Activity的非静态内部类，当Activity需销毁时，会因AsyncTask保留对Activity的引用而导致Activity无法被回收，最终引起内存泄漏
* 使用建议
  * AsyncTask应被声明为Activity的静态内部类

### 7.3 线程任务执行结果丢失

* 结论
  * 当Activity重新创建（屏幕旋转/被意外销毁后恢复），之前运行的AsyncTask（非静态的内部类）持有的之前Activity引用已无效，故复写的onPostExcute()将不生效，即无法更新UI操作
* 使用建议
  * 在Activity中恢复时的对应方法 重启 任务线程

## 8 源码分析

详见前辈的文章

[Android 多线程：AsyncTask的原理 及其源码分析](https://www.jianshu.com/p/37502bbbb25a)

