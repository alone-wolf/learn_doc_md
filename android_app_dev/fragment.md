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