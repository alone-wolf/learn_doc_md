# 使用代码构建UI界面

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

### 0x03 java/kotlin都是类似

to be contioue