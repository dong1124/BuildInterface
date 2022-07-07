@echo off
chcp 65001

if "%~1" == "Windows" (
	color 17
	@mode con lines=60 cols=95
) else (@mode con lines=40 cols=88)
title %~1_Build



set PLAT=%~1
set DST_BRANCH=%~2
set EDITION=%~3
set NUM=%~4
set LAST_DATE=%~5
set ISAUTODOWN=%~6



@echo 传入参数如下:
@echo 构建平台: %PLAT%
@echo 目标分支: %DST_BRANCH%
@echo 版本号: %EDITION%
@echo 序号: %NUM%
@echo 上次发版日期: %LAST_DATE%
@echo 是否自动下载: %ISAUTODOWN%

@echo .
pause
exit