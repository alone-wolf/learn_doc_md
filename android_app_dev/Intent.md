# Intent 使用

### 通过浏览器打开url

java

```java
Uri uri = Uri.parse("https://www.baidu.com");
Intent intent = new Intent(Intent.ACTION_VIEW, uri);
startActivity(intent);
```

### 启动指定浏览器打开

java

```java
Uri uri = Uri.parse("https://www.baidu.com");
Intent intent = new Intent(Intent.ACTION_VIEW,uri);
//intent.setClassName("com.UCMobile","com.uc.browser.InnerUCMobile");//打开UC浏览器
intent.setClassName("com.tencent.mtt","com.tencent.mtt.MainActivity");//打开QQ浏览器
startActivity(intent);
```

### 启动Activity/Service

kotlin

```kotlin
val intent = Intent(context,RecvActivity::class.java)
startActivity(intent)
```

```kotlin
val intent = Intent(context,RecvActivity::class.java)
intent.putExtra("text","value")
startActivity(intent)
```

