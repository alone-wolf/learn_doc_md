# 操作事件

### 长按事件 kotlin

```kotlin
bShowGreen.setOnLongClickListener {
  println("bShowGreen LongClicked!")
  return@setOnLongClickListener true
}
```

或者简写成

```kotlin
bShowGreen.setOnLongClickListener{
  println("bShowGreen LongClicked!")
  true
}
```

