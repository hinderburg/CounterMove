all:
	./build_native.sh NDK_DEBUG=1
	ant -Dsdk.dir=${SDK_ROOT} debug
run:
	adb -d uninstall com.BananaHedgehog.CounterMove
	adb -d install bin/CounterMove.apk
	adb -d logcat | grep cocos2d
clean:
	rm -rf libs/
	rm -rf obj/
	rm -rf bin/*
	rm -rf gen/
	rm -rf assets/*
