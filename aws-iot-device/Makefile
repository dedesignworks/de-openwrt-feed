include $(TOPDIR)/rules.mk

PKG_NAME:=aws-iot-device
PKG_VERSION:=202412.00
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=git@github.com:aws/aws-iot-device-sdk-embedded-C.git
PKG_SOURCE_VERSION:=202412.00
CMAKE_INSTALL:=1
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/aws-iot-device
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://github.com/aws/aws-iot-device-sdk-embedded-C.git
  TITLE:=AWS IoT Core device libraries
  DEPENDS:=+libopenssl
endef

define Package/aws-iot-device/description
  Libraries for securely connecting a device to AWS IoT Core. This package contains MQTT client, HTTP client, JSON Parser, AWS IoT Device Shadow, AWS IoT Jobs, and AWS IoT Device Defender libraries.
endef

CMAKE_BINARY_SUBDIR:=build

CMAKE_OPTIONS+= \
	-DINSTALL_PLATFORM_ABSTRACTIONS:bool=ON \
	-DBUILD_DEMOS:bool=OFF \
	-DINSTALL_TO_SYSTEM:bool=ON \
	-DCMAKE_SKIP_RPATH=OFF \
	-DCMAKE_INSTALL_RPATH="/usr/lib/aws" \
	-DBUILD_CLONE_SUBMODULES:bool=ON \
	-DMQTT_CUSTOM_CONFIG_DIR=$(PKG_BUILD_DIR)/mqtt_config

define Build/Configure
	# Copy sigv4_config.h from files directory
	mkdir -p $(PKG_BUILD_DIR)/sigv4_config
	cp ./files/sigv4_config.h $(PKG_BUILD_DIR)/sigv4_config/
	# Copy core_mqtt_config.h from files directory
	mkdir -p $(PKG_BUILD_DIR)/mqtt_config
	cp ./files/core_mqtt_config.h $(PKG_BUILD_DIR)/mqtt_config/
	echo 'include(libraries/aws/sigv4-for-aws-iot-embedded-sdk/sigv4FilePaths.cmake)' >> $(PKG_BUILD_DIR)/CMakeLists.txt
	echo 'add_library(sigv4 $$$${SIGV4_SOURCES})' >> $(PKG_BUILD_DIR)/CMakeLists.txt
	echo 'target_include_directories(sigv4 PUBLIC $$$${SIGV4_INCLUDE_PUBLIC_DIRS} $$$${CMAKE_CURRENT_SOURCE_DIR}/sigv4_config)' >> $(PKG_BUILD_DIR)/CMakeLists.txt
	echo 'install(TARGETS sigv4 DESTINATION "$$$${CSDK_LIB_INSTALL_PATH}")' >> $(PKG_BUILD_DIR)/CMakeLists.txt
	echo 'install(DIRECTORY "$$$${CMAKE_CURRENT_LIST_DIR}/libraries/aws/sigv4-for-aws-iot-embedded-sdk/source/include/" DESTINATION "$$$${CSDK_HEADER_INSTALL_PATH}")' >> $(PKG_BUILD_DIR)/CMakeLists.txt
	echo 'install(FILES sigv4_config/sigv4_config.h DESTINATION "$$$${CSDK_HEADER_INSTALL_PATH}")' >> $(PKG_BUILD_DIR)/CMakeLists.txt
	echo 'target_include_directories(aws_iot_mqtt BEFORE PUBLIC $$$${CMAKE_CURRENT_SOURCE_DIR}/mqtt_config $$$${CMAKE_CURRENT_SOURCE_DIR}/demos/logging-stack)' >> $(PKG_BUILD_DIR)/CMakeLists.txt
	echo 'install(TARGETS tinycbor mbedtls DESTINATION "lib/aws")' >> $(PKG_BUILD_DIR)/libraries/3rdparty/CMakeLists.txt
	$(call Build/Configure/Default)
endef

define Package/aws-iot-device/install
	$(INSTALL_DIR) $(1)/usr/lib/aws
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/aws/lib*.so* $(1)/usr/lib/aws/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib*.so* $(1)/usr/lib/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/* $(1)/
endef

$(eval $(call BuildPackage,aws-iot-device))