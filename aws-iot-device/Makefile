include $(TOPDIR)/rules.mk

PKG_NAME:=aws-iot-device
PKG_VERSION:=202211.00
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=https://github.com/dedesignworks/aws-iot-device-sdk-embedded-C.git
PKG_SOURCE_VERSION:=7f8551bcaa8d811c44473db7755965a5316e3a7d
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
	-DCMAKE_INSTALL_RPATH="/usr/lib/aws"

define Package/aws-iot-device/install
	$(INSTALL_DIR) $(1)/usr/lib/aws
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/aws/lib*.so* $(1)/usr/lib/aws/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib/aws
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/* $(1)/
endef

$(eval $(call BuildPackage,aws-iot-device))