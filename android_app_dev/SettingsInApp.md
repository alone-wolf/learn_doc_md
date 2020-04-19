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

### 0x03 部件

1. PreferenceCategory

   * 一个组，用来包含多个preference
   * title 这个组的标题

2. Preference

   * 一个啥也没有的项，貌似是其他几个的父类
   * key 相当于btn的id，用于定位
   * title 显示的标题
   * summary 标题下面的简单显示
   * icon 不用说

3. CheckPreference

   * 只是有个勾选框

4. SwitchPreference

5. DropDownPreference

   * entries 下拉菜单的选项

   * entryValues 下拉菜单的值

   * 下面这个放在string.xml文件里resource标签内，和string标签同级

   * ```xml
     <string-array
       name="string_array_name">
       <item>text_string</item>
     </string-array>
     ```

6. SeekBarPreference
   * defaultValue 默认值
   * max 最大值
7. ListPreference
8. MultiSelectListPerference

### 0x04 获取值

java

```java
SharedPreferences sharedPreferences =
   PreferenceManager.getDefaultSharedPreferences(this);
		//Activity context
String name = sharedPreferences.getString(“key”, "");
```

kotlin

```kotlin
val sharedPreferences = PreferenceManager
	.getDefaultSharedPreferences(this /* Activity context */)
val name = sharedPreferences.getString("signature", "")
```

### 0x05 设置值

