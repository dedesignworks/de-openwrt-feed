include $(TOPDIR)/rules.mk

PKG_NAME:=cryptoauthlib
PKG_VERSION:=3.7.9
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=https://github.com/MicrochipTech/cryptoauthlib.git
PKG_SOURCE_VERSION:=7f0015615a70671814a8dd956c8318d1b922791e
CMAKE_INSTALL:=1
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cryptoauthlib
  SECTION:=libs
  CATEGORY:=Libraries
  URL:=https://github.com/MicrochipTech/cryptoauthlib.git
  TITLE:=Microchip CryptoAuthentication Library
  DEPENDS:=+libopenssl
endef

define Package/cryptoauthlib/description
  Use cryptoauthlib as a pkcs11 provider.
endef

CMAKE_OPTIONS += \
	-DATCA_HAL_I2C=ON \
	-DATCA_PKCS11=ON \
	-DATCA_OPENSSL=ON \
	-DATCA_ATECC508A_SUPPORT=ON \
	-DATCA_ATECC608_SUPPORT=ON \
	-DATCA_BUILD_SHARED_LIBS=ON \
	-DATCA_TNGTLS_SUPPORT=ON \
	-DATCA_TNGLORA_SUPPORT=ON \
	-DATCA_TFLEX_SUPPORT=ON \
	-DATCA_USE_ATCAB_FUNCTIONS=ON

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcryptoauth.so* $(1)/usr/lib/
endef

define Package/cryptoauthlib/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libcryptoauth.so* $(1)/usr/lib/
	$(INSTALL_DIR) $(1)/etc/cryptoauthlib
	$(CP) $(PKG_INSTALL_DIR)/$(PKG_BUILD_DIR)/etc/cryptoauthlib/* $(1)/etc/cryptoauthlib/
	${INSTALL_DIR} $(1)/usr/share/cryptoauthlib
	${INSTALL_DATA} $(PKG_INSTALL_DIR)/$(PKG_BUILD_DIR)/var/lib/cryptoauthlib/* $(1)/usr/share/cryptoauthlib/
endef

$(eval $(call BuildPackage,cryptoauthlib))
