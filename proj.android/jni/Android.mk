LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS += -fuse-ld=gold

SRC_DIRS := $(shell find $(LOCAL_PATH)/../../Classes -type d -print)
SRCS     := $(foreach DIR, $(SRC_DIRS), $(wildcard $(DIR)/*.cpp))

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   $(subst jni/, , $(SRCS))
                   
LOCAL_C_INCLUDES := $(SRC_DIRS)   

#delete -DCOCOS2D_DEBUG=1 -g in release version
#DMAIN_JAVA_CLASS used for JNI
#LOCAL_CPPFLAGS := -DCOCOS2D_DEBUG=1 \
#                  -DMAIN_JAVA_CLASS='"org/smartbit/pianorhapsody/pianorhapsody"'                

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static \
								cocosdenshion_static \
								cocos_extension_static \
								chipmunk_static \
								cocos_lua_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions) \
$(call import-module,external/chipmunk) \
$(call import-module,scripting/lua/proj.android/jni)
