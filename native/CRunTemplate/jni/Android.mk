LOCAL_PATH := $(call my-dir)
  
include $(CLEAR_VARS)
  
LOCAL_MODULE        := CRunTemplate

LOCAL_LDLIBS        := -llog -lGLESv2
LOCAL_CPP_EXTENSION := .cc
LOCAL_SRC_FILES     := ../../base/NativeExtension.cc Extension.cc
LOCAL_CFLAGS        := -DThisExtension=$(LOCAL_MODULE) -fvisibility=hidden -fno-exceptions -fno-rtti -I../../base
LOCAL_LDFLAGS       := -L../../../android/assets

include $(BUILD_SHARED_LIBRARY)

