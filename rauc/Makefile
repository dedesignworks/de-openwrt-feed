include $(TOPDIR)/rules.mk

PKG_NAME:=rauc
PKG_VERSION:=v1.11.2
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/rauc/rauc.git
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_VERSION:=d8ce080ba1b2886eea70b8a7f9c1492763f71b77

PKG_MAINTAINER:=DE Design Works <info@dedesignworks.com>

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/meson.mk

MESON_ARGS += \
	-Dservice=false

define Package/rauc
	SECTION:=utils
	CATEGORY:=Base system
	TITLE:=Robust Auto-Update Controller
	DEPENDS:=+glib2 +libnl +libopenssl +libcurl +libiconv-full +libfdisk +json-glib
endef

define Package/rauc/description
RAUC controls the update process on embedded Linux systems.
It is both a target application that runs as an update client and a host/target tool that allows you to create, inspect and modify installation artifacts.
endef

define Package/rauc/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/rauc $(1)/usr/bin/rauc
endef

define Package/rauc/postinst
	#!/bin/sh
	[ -n "$${IPKG_INSTROOT}" ] && exit 0
	exit 0
endef

$(eval $(call BuildPackage,rauc))