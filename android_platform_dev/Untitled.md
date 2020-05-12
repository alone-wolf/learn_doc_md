repo init -u ssh://alone-wolf@mokeedev.review:29418/MoKee/android --depth 10 -b mkq-mr1 

repo sync --force-sync -j8

. build/envsetup.sh
lunch mokee_cancro-userdebug
mka bacon

为解决共享库丢失问题
sudo apt install libncurses5

make clobber 清除顶层目录下的out/
make clean 清除out/target/product/[product_name]
