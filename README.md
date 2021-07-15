## 编译

### Windows平台

**生成Visual Studio 2019工程**

```bash
# 配置vs开发环境
%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat"
mkdir build
cd build

# 生成vs工程
cmake -G "Visual Studio 16 2019" -A Win32 ../ -DCMAKE_PREFIX_PATH:STRING=/Users/syzby/Qt5.14.2/5.14.2/clang_64
cmake -G "Visual Studio 16 2019" -A x64 ../ -DCMAKE_PREFIX_PATH:STRING=C:\Qt\Qt5.14.2\5.14.2\msvc2017_64

# 编译
cmake --build .
```

**生成Visual Studio 2015工程**

```bash

# 配置vs开发环境
%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\Tools\VsDevCmd.bat"

# 生成vs工程
#32位版本
cmake -G "Visual Studio 14 2015" .. -DCMAKE_PREFIX_PATH:STRING=C:/Qt/Qt5.9.6/5.9.6/msvc2015
#64位版本
cmake -G "Visual Studio 14 2015 Win64" .. -DCMAKE_PREFIX_PATH:STRING=C:/Qt/Qt5.12.2/5.12.2/msvc2015_64

# 编译 debug版本
cmake --build .

# 编译 release版本
cmake --build . --target "ALL_BUILD" --config "Release"

# 编译带调试信息版本
cmake --build . --target "ALL_BUILD" --config "RelWithDebInfo"

```