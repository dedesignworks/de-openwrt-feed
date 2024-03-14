include $(TOPDIR)/rules.mk

PKG_NAME:=cryptoauthlib
PKG_VERSION:=3.7.4
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=https://github.com/MicrochipTech/cryptoauthlib.git
PKG_SOURCE_VERSION:=9a5b711582b3df0ed97fa6147c899eb856c52d34
CMAKE_INSTALL:=1

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

$(eval $(call BuildPackage,cryptoauthlib))
