include $(TOPDIR)/rules.mk

PKG_NAME:=lvgl-lib
PKG_VERSION:=9.2-8b106e2
PKG_RELEASE:=1

# Git source: https://github.com/lvgl/lv_port_linux/tree/release/v9.2
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://packages.dedesignworks.com/source/
PKG_HASH:=f02abbb2537c8535536bc1c0073dccba6913f11e87b7dd952de00e5e48214103

CMAKE_INSTALL:=1
PKG_INSTALL:=1
CMAKE_OPTIONS+= "-DBUILD_SHARED_LIBS=ON"

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

PKG_BUILD_DEPENDS := libdrm

define Package/lvgl-lib
	SECTION:=graphics
	CATEGORY:=graphics
	DEPENDS:=+libstdcpp +libdrm
	TITLE:=LVGL Graphics Library
endef

define Package/lvgl-lib/description
	LVGL Graphics Library
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib $(1)/usr/lib/pkgconfig
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/liblvgl.so* $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/liblvgl_thorvg.so* $(1)/usr/lib/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/lvgl.pc $(1)/usr/lib/pkgconfig
endef

define Package/lvgl-lib/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/liblvgl.so* $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/liblvgl_thorvg.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,lvgl-lib))
