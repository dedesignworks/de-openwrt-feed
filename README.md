# DE Design Works OpenWrt packages feed

## Description

This is the OpenWrt "packages"-feed maintained by DE Design Works.
This contains build scripts, options and patches for applications, modules and libraries used within OpenWrt.

Installation of pre-built packages is handled directly by the **opkg** utility within your running OpenWrt system or by using the [OpenWrt SDK](https://openwrt.org/docs/guide-developer/using_the_sdk) on a build system.

## Usage

This repository is intended to be layered on-top of an OpenWrt buildroot. If you do not have an OpenWrt buildroot installed, see the documentation at: [OpenWrt Buildroot – Installation](https://openwrt.org/docs/guide-developer/build-system/install-buildsystem) on the OpenWrt support site.

This feed is enabled by adding the following line to `feeds.conf` in OpenWrt:

    src-git de https://github.com/dedesignworks/de-openwrt-feed.git;main

And then running the following:

```
./scripts/feeds update de
./scripts/feeds install -a -p de
```
