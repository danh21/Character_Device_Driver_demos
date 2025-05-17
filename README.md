# 📦 Project Name

> Investigate operation of character device driver.

---

## 📚 Table of Contents

- [📦 Project Name](#-project-name)
  - [📚 Table of Contents](#-table-of-contents)
  - [📝 About](#-about)
  - [✨ Features](#-features)
  - [🚀 Getting Started](#-getting-started)
    - [Prerequisites](#prerequisites)
    - [Source](#source)
    - [Usage](#usage)
    - [Reference](#reference)

---

## 📝 About

> This repo includes small demos to test operation of character device driver.

---

## ✨ Features

- ✅ Register the character device with Linux Kernel (allocate device number, create 1 device node / multiple device nodes, create class)
- ✅ Test file operations (open, close, read, write, seek, ioctl) between kernel and user
- ✅ Ability to compatible to 32-bit .exe
- ✅ Send signal from kernel module to process
- ✅ Control access to device file
- ✅ Operation of capabilities

---

## 🚀 Getting Started

### Prerequisites

- List software dependencies or system requirements here:
  - Linux kernel
  - Ubuntu
  - C Linux
  - Makefile

### Source

- *.c: main app
- Makefile: make utility to build
- *.ko: kernel object (add to kernel), link from other *.o files
- *.mod: describe module, used in build progress
- *.mod.c: metadata about kernel module
- *.o: object file
- Module.symvers: contain symbol list (func, var...) exported by kernel and modules
- modules.order: list modules by build order

### Usage

- cd to workspace folder
- Make file: **$ make**
- Install module: **$ sudo insmod .ko**
- Check info of module: **$ modinfo .ko**
- Check operation of kernel in real-time: **$ sudo dmesh -wH**
- Remove module: **$ sudo rmmod .ko**

### Reference

- https://www.udemy.com/course/character-device-drivers-in-deep/
