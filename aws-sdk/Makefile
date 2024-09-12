include $(TOPDIR)/rules.mk

PKG_NAME:=aws-sdk
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=https://github.com/aws/aws-iot-device-sdk-embedded-C.git
PKG_SOURCE_VERSION:=2d1dacd946b5d9612439559655ad9fd1b0895940
PKG_MIRROR_HASH:=2d4bbf56b7cb6ee48ed8e790b2407a526477c93df544ac386b57fdb07ace9c37
CMAKE_INSTALL:=1
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/aws-sdk
	SECTION:=aws-sdk
	CATEGORY:=Libraries
	DEPENDS:=libopenssl
	TITLE:=Library for aws-sdk
endef

define Package/aws-sdk/description
	Library for aws-sdk
endef

CMAKE_BINARY_DIR:=$(CMAKE_SOURCE_DIR)/build

CMAKE_OPTIONS+= \
	-DINSTALL_PLATFORM_ABSTRACTIONS:bool=OFF \
	-DBUILD_DEMOS:bool=OFF \
	-DINSTALL_TO_SYSTEM:bool=ON \


define Package/aws-sdk/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_backoff_algorithm.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_defender.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_http.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_jobs.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_json.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_mqtt.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_ota_http.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_ota_mqtt.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_ota.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libaws_iot_pkcs.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libclock_posix.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libopenssl_posix.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libplaintext_posix.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libsockets_posix.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libtinycbor.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libmbedtls.so* $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/build/lib/libtransport_mbedtls_pkcs11_posix.so* $(1)/usr/lib/
endef

define Build/InstallDev
  	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/build/lib/lib*.so* $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/include/aws $(1)/usr/include/
endef

$(eval $(call BuildPackage,aws-sdk))