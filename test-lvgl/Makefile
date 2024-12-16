include $(TOPDIR)/rules.mk

PKG_NAME:=test-lvgl
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

PKG_BUILD_DEPENDS := lvgl
SOURCE_DIR:=/workspaces/herdstar-gateway/openwrt/package/feeds/de/test-lvgl/src

define Build/Prepare
	$(if $(SOURCE_DIR),cp -r $(SOURCE_DIR)/* $(PKG_BUILD_DIR); $(Build/Patch), $(call Build/Prepare/Default))
endef

define Package/test-lvgl
	SECTION:=graphics
	CATEGORY:=graphics
	TITLE:=LVGL example program
	DEPENDS:=+lvgl-lib
endef

define Package/test-lvgl/description
	LVGL Example program
endef

define Package/test-lvgl/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_BUILD_DIR)/bin/test-lvgl $(1)/usr/bin/
endef

$(eval $(call BuildPackage,test-lvgl))
