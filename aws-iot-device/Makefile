include $(TOPDIR)/rules.mk

PKG_NAME:=aws-iot-device
PKG_VERSION:=202211.00
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=https://github.com/aws/aws-iot-device-sdk-embedded-C.git
PKG_SOURCE_VERSION:=18f9653d339b4e98d720a7ca899a5e4947f6de53
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
	-DINSTALL_PLATFORM_ABSTRACTIONS:bool=OFF \
	-DBUILD_DEMOS:bool=OFF \
	-DINSTALL_TO_SYSTEM:bool=ON \

define Package/aws-iot-device/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib*.so* $(1)/usr/lib/
	$(CP) $(CMAKE_BINARY_DIR)/lib/libtinycbor.so $(1)/usr/lib/
	$(CP) $(CMAKE_BINARY_DIR)/lib/libmbedtls.so $(1)/usr/lib/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/* $(1)/
	$(CP) $(CMAKE_BINARY_DIR)/lib/libtinycbor.so $(1)/usr/lib/
	$(CP) $(CMAKE_BINARY_DIR)/lib/libmbedtls.so $(1)/usr/lib/
endef

$(eval $(call BuildPackage,aws-iot-device))