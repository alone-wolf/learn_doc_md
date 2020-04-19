# IntentService

祭出前辈的文章

[Android多线程：IntentService使用教程（含实例讲解）](https://www.jianshu.com/p/af62781fefba)

[Android多线程：这是一份全面 & 详细的IntentService源码分析指南](https://www.jianshu.com/p/8a3c44a9173a)

## 简介

* 定义
  * Android里的一个多线程封装类
  * 继承service组件
* 作用
  * 处理异步请求&实现多线程
* 使用场景
  * 线程任务需按顺序、在后台执行
  * 最常见的场景，离线下载
  * 不符合多个数据同时请求的场景 所有任务都是在同一个Thread Looper中执行

## 使用步骤

1. 定义IntentService的子类，需重写onHandleIntent方法
2. 在Manifest.xml中注册服务
3. 在Activity中启动服务

## 实例

* 定义IntentService的子类

传入线程名称，复写onHandleIntent方法

```java
public class myIntentService extends IntentService {

  /** 
    * 在构造函数中传入线程名字
    **/  
    public myIntentService() {
        // 调用父类的构造函数
        // 参数 = 工作线程的名字
        super("myIntentService");
    }

   /** 
     * 复写onHandleIntent()方法
     * 根据 Intent实现 耗时任务 操作
     **/  
    @Override
    protected void onHandleIntent(Intent intent) {

        // 根据 Intent的不同，进行不同的事务处理
        String taskName = intent.getExtras().getString("taskName");
        switch (taskName) {
            case "task1":
                Log.i("myIntentService", "do task1");
                break;
            case "task2":
                Log.i("myIntentService", "do task2");
                break;
            default:
                break;
        }
    }

    @Override
    public void onCreate() {
        Log.i("myIntentService", "onCreate");
        super.onCreate();
    }
   /** 
     * 复写onStartCommand()方法
     * 默认实现 = 将请求的Intent添加到工作队列里
     **/  
    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.i("myIntentService", "onStartCommand");
        return super.onStartCommand(intent, flags, startId);
    }

    @Override
    public void onDestroy() {
        Log.i("myIntentService", "onDestroy");
        super.onDestroy();
    }
}
```

* 在清单中注册服务

```xml
<service android:name=".myIntentService">
  <intent-filter >
    <action android:name="cn.scu.finch"/>
  </intent-filter>
</service>
```

* 在Activity中开启Service

```java
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

            // 同一服务只会开启1个工作线程
            // 在onHandleIntent（）函数里，依次处理传入的Intent请求
            // 将请求通过Bundle对象传入到Intent，再传入到服务里

            // 请求1
            Intent i = new Intent("cn.scu.finch");
            Bundle bundle = new Bundle();
            bundle.putString("taskName", "task1");
            i.putExtras(bundle);
            startService(i);

            // 请求2
            Intent i2 = new Intent("cn.scu.finch");
            Bundle bundle2 = new Bundle();
            bundle2.putString("taskName", "task2");
            i2.putExtras(bundle2);
            startService(i2);

            startService(i);  //多次启动
        }
    }
```

## 对比

* 与service的区别

| 类型          | 运行线程                                | 结束服务操作                                       | 备注                                                         |
| ------------- | --------------------------------------- | -------------------------------------------------- | ------------------------------------------------------------ |
| IntentService | 创建一个工作线程处理多线程任务          | 不需要，在所有Intent处理完毕后，系统会自动关闭服务 | IntentService为Service的onBind提供了默认实现，返回null       |
| Service       | 主线程，不能处理耗时操作，否则会触发ANR | 需主动调用stopService()                            | IntentService 为 Service的onStartCommand()提供了默认实现，将请求的Intent添加到队列中 |

* 与其他线程的区别

| 类型          | 线程属性                            | 作用                  | 线程优先级                                                   |
| ------------- | ----------------------------------- | --------------------- | ------------------------------------------------------------ |
| IntentService | 类似后台线程，采用HandlerThread实现 | 后台服务，继承Service | 高，不容易被系统杀死                                         |
| 其他线程      | 普通线程                            | 普通多线程作用        | 低，如果进程中无活动的四大组件，则该线程的优先级非常低，容易被系统杀死 |

