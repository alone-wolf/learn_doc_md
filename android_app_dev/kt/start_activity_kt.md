# Android Develop - start activity/service

### only start

1. `val intent = Intent(this,TargetActivity::class.java)` 

2. `startActivity(this,TargetActivity::class.java)` 

in TargetActivity

3. `nothing to do` 

### start activity with extra

1. `val intent = Intent(this,TargetActivity::class.java)` 

2. `intent.putExtra("key","this is a msg")`

3. `startActivity(intent)`

or

1. `val intent = Intent(this,TargetActivity::class.java)` 

2. `val bundle = Bundle()`

3. `bundle.putString("name","this is a msg")`

4. `startActivity(intent)` 

