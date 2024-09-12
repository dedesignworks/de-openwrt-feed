include $(TOPDIR)/rules.mk

PKG_NAME:=azure-iot
PKG_VERSION:=LTS_08_2024
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=https://github.com/Azure/azure-iot-sdk-c.git
PKG_SOURCE_VERSION:=9c70f98b7b659e169ae44389a5142f3a386c5791
CMAKE_INSTALL:=1
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/azure-iot
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://github.com/Azure/azure-iot-sdk-c.git
  TITLE:=Azure IOT Hub device libraries
  DEPENDS:=+curl +libopenssl +libuuid +ca-certificates
endef

define Package/azure-iot/description
  Libraries for connecting devices to Microsoft Azure IoT services.
endef

CMAKE_BINARY_SUBDIR:=build

CMAKE_OPTIONS+= \
	-Duse_mqtt:bool=ON \
	-Dskip_samples:bool=ON \
	-Dbuild_service_client:bool=OFF \
	-Dbuild_provisioning_service_client:bool=OFF \
	-Dbuild_as_dynamic:bool=ON \

define Package/azure-iot/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib*.so* $(1)/usr/lib/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib*.{a,so*} $(1)/usr/lib/
endef

$(eval $(call BuildPackage,azure-iot))