# 应用内发起分享和分享的接收

### 分享动作的发起

1. kotlin

   ```kotlin
   val sendIntent = Intent()
   sendIntent.action = Intent.ACTION_SEND
   sendIntent.putExtra(Intent.EXTRA_TEXT,etText.text.toString())
   sendIntent.type = "text/plain"
   
   val shareIntent = Intent.createChooser(sendIntent,null)
   startActivity(shareIntent)
   ```

2. java

   on the way

### 分享动作的接收

1. 清单 将如下代码放到接收分享的activity中

   ```xml
   <intent-filter>
       <action android:name="android.intent.action.SEND" />
       <category android:name="android.intent.category.DEFAULT" />
       <data android:mimeType="text/plain" />
   </intent-filter>
   ```

2. 接收分享的activity中

   ```java
   Intent intent = getIntent();
   String action = intent.getAction();
   String type = intent.getType();
   
   if (Intent.ACTION_SEND.equals(action) && type != null) {
       switch (type){
           case "text/plain":{
               String text = intent.getStringExtra(Intent.EXTRA_TEXT);
               Log.d(lTAG, "recv data>0 "+text);
               break;
           }
           default:{
               Log.e(lTAG,"recv wrong type");
               break;
           }
       }
   }
   ```

