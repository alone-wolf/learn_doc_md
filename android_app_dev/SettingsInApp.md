# 设置界面构建方法

#### 从Android 10 开始，官方已经弃用了android.preference

#### 现在开始使用新的库

`androidx.preference:preference`

### 0x00 添加gradle依赖

这里不用多说，在项目设置里面搜索并添加就行了

### 0x01 创建xml资源

```xml
<PreferenceScreen
    xmlns:app="http://schemas.android.com/apk/res-auto">
    <SwitchPreferenceCompat
        app:key="notifications"
        app:title="Enable message notifications"/>
    <Preference
        app:key="feedback"
        app:title="Send feedback"
        app:summary="Report technical issues or suggest new features"/>
</PreferenceScreen>
```

将上面的代码保存到xml文件夹中新建的文件中，名称自定，建议使用pre-xxx.xml

如果没有xml文件夹，可以在res文件夹中创建xml文件夹

### 0x02 fragment代码

#### java

``` java
public class MySettingsFragment extends PreferenceFragmentCompat {
    @Override
    public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
        setPreferencesFromResource(R.xml.preferences, rootKey);
    }
}
```

#### kotlin

```kotlin 
class MySettingsFragment : PreferenceFragmentCompat() {
    override fun onCreatePreferences(savedInstanceState: Bundle?, rootKey: String?) {
        setPreferencesFromResource(R.xml.preferences, rootKey)
    }
}
```

