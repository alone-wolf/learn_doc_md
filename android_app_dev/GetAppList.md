# android dev get app list

    private void getAppList(){
        PackageManager pm = getPackageManager();
        List<PackageInfo> packages = pm.getInstalledPackages(0);
        for (PackageInfo pInfo : packages){
            if((pInfo.applicationInfo.flags & ApplicationInfo.FLAG_SYSTEM) == 0){
                //user app
                Log.d("TAG",pInfo.packageName);
            }else{
                //sys app
            }
    
            //get packagename
            String packageName = pInfo.packageName;
            
            //get app info
            ApplicationInfo appInfo = pInfo.applicationInfo;
            
            //get icon
            Drawable icon = appInfo.loadIcon(pm);
    
            String appName = appInfo.loadLable(pm).toString();
        }
    }




