# Android Fragment

* fragment 有自己的生命周期
* fragment 依赖于Act
* 通过getActivity()获取所在Act; Act通过FragmentManager的findFragmentById()或findFragmentByTag()获取Fragment

* Fragment Activity multi to multi




### fragment 完整的生命周期

| Activity  | Fragment          |
| --------- | :---------------- |
| Created   | onAttach          |
|           | onCreate          |
|           | onCreateView      |
|           | onActivityCreated |
| Started   | onStarted         |
| Resumed   | onResume          |
| Paused    | onPause           |
| Stopped   | onStop            |
| Destroyed | onDestroyView     |
|           | onDestroy         |
|           | onDeatch          |



**onAttach() ：**
 当Fragment与Activity发生关联时调用。

**onCreate()：**
 创建Fragment时被回调。

**onCreateView()：**
 每次创建、绘制该Fragment的View组件时回调该方法，Fragment将会显示该方法返回的View 组件。

**onActivityCreated()：**
 当 Fragment 所在的Activity被启动完成后回调该方法。

**onStart()：**
 启动 Fragment 时被回调，此时Fragment可见。

**onResume()：**
 恢复 Fragment 时被回调，获取焦点时回调。

**onPause()：**
 暂停 Fragment 时被回调，失去焦点时回调。

**onStop()：**
 停止 Fragment 时被回调，Fragment不可见时回调。

**onDestroyView()：**
 销毁与Fragment有关的视图，但未与Activity解除绑定。

**onDestroy()：**
 销毁 Fragment 时被回调。

**onDetach()：**
 与onAttach相对应，当Fragment与Activity关联被取消时调用。



### 生命周期调用

1. 创建fragment

   onAttach -> onCreate -> onCreateView -> onActivityCreated -> onStart -> onResume

2. 按下home 回到桌面/锁屏

   onPause -> onStop

3. 从桌面回到fragment/解锁

   onStart -> onResume

4. 切换到其他fragment

   onPause -> onStop -> onDestroyView

5. 切换回本身的fragment

   onCreateView -> onActivityCreated -> onStart -> onResume

6. 按下back退出

   onPause -> onStop -> onDestroyView -> onDestroy -> onDetach

   