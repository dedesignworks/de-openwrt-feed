include $(TOPDIR)/rules.mk

PKG_NAME:=cloud-apps
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=https://github.com/dedesignworks/cloud-apps.git
PKG_SOURCE_VERSION:=148cd26cb8c5e6f78e4841593deb2bcc7c8c74c2
CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cloud-send
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libjson-c +curl +libopenssl +libuuid +ca-certificates
	TITLE:=Cloud Send Message Application
endef

define Package/cloud-send/description
	Application to send messages to the cloud.
endef

define Package/cloud-provision
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libjson-c +curl +libopenssl +libuuid +ca-certificates
	TITLE:=Cloud Provisioning Application
endef

define Package/cloud-provision/description
	Application for provisioning the IoT device with the cloud.
endef

define Package/swordfish-cloud-send/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/cloud-send $(1)/usr/bin
endef

define Package/cloud-provision/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/cloud-provision $(1)/usr/bin
endef

$(eval $(call BuildPackage,cloud-send))
$(eval $(call BuildPackage,cloud-provision))
