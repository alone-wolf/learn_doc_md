# Android 使用代码构建UI界面

### 0x00

据纯纯写作的作者 xxx 说，使用java/kotlin绘制的ui界面的构建速度要优于xml绘制的layout，因此我开始了初学者的探索
### 0x01 Activity
众所周知，Activity在onCreate回调方法中通过setContent()方法来设置界面

这个方法的参数既可以是int类型的R.layout.main_activity这种格式

还可以是实例化的xxlayout对象

使用方法类似于用js操作dom创建web页面元素

先实例化layout比如

`LinearLayout l = new LinearLayout(context);`

`Button btn = new Button(context);`

然后向linearlayout中添加对象，也就各种view

`l.addView(btn);`

最后设置content

### 0x02 Fragment

在onCeateView回调方法中按照上述的方法创建各种实例对象

将各种view添加到layout后，直接return该layout

### 0x04 TextView Button 等设置属性

java

```java
Button btn = new Button(context);
btn.setText("this is a btn");
btn.setTextSize(20); //float
btn.setOnClickListener(new View.OnClickListener(){
  @Override
  public void onClick(View v){
    // thhings
  }
});

// new 的控件 使用如下方法设置layout属性
LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
layoutParams.setMargins(10,10,10,10);//4个参数按顺序分别是左上右下
textview.setLayoutParams(layoutParams);

// xml中已经存在的
LinearLayout.LayoutParams lp = (LinearLayout.LayoutParams) textview.getLayoutParams();
lp.leftMargin = 0;
textview.setLayoutParams(lp);
```

to be contioue

