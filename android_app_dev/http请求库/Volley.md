# Volly 使用

#### volley是google开发的一个http请求库

gradle依赖

```gradle
implementation 'com.android.volley:volley:1.1.1'
```

### 这里只说一个坑

如果请求的内容没有指定使用什么编码，volley会非常智障得把编码改成iso-8859-1，而不是utf8