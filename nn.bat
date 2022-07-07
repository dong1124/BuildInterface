@echo off
chcp 65001

if "%~1" == "Windows" (
	color 17
	@mode con lines=60 cols=95
) else (@mode con lines=40 cols=88)
title %~1_Build





set PLAT=%~1

set USER_IP=%~2
set GIT_USER_KEY=%~3
set SRC_PATH=%~4
set PUBLISH_PATH=%~5


set DST_BRANCH=%~6
set EDITION=%~7
:: 从mfc传入当前时间，避免BAT因编码不同，日期格式不同
set NOWDAY=%~8 
set NUM=%~9

@echo 传入参数如下
@echo PLAT: %~1
@echo USER_IP: %~2
@echo GIT_USER_KEY: %~3
@echo SRC_PATH: %~4
@echo PUBLISH_PATH: %~5
@echo DST_BRANCH: %~6
@echo EDITION: %~7
@echo NOWDAY: %~8
@echo NUM: %~9


:: 超过9个参数，需要用shift偏移处理获取
shift /0
set ISAUTODOWN=%~9
@echo ISAUTODOWN: %~9
shift /0
set STARTDATE=%~9
@echo STARTDATE: %~9
:: STARTDATE 此处不做判空，命令行参数 会将1 week 空格断开

SET LOG=%NOWDAY%.log

call:checkfun "%PLAT%" "PLAT 平台类型"
call:checkfun "%USER_IP%" "USER@IP 用户名@远程机器IP"
::call:checkfun "%GIT_USER_KEY%" "GIT_USER_KEY git用户:密码"
call:checkfun "%SRC_PATH%" "SRC_PATH 远程机器代码路径"
call:checkfun "%PUBLISH_PATH%" "PUBLISH_PATH 远程机器脚本路径"
call:checkfun "%DST_BRANCH%" "DST_BRANCH 目标分支"
call:checkfun "%EDITION%" "EDITION 版本号"

if "%NUM%" == "" (
	set NUM=1
)
if "%ISAUTODOWN%" == "" (
	set ISAUTODOWN=n
)



:: 远程连接服务器执行ssh_publish_x脚本进行构建打包
if "%PLAT%" == "Windows" (
	@ECHO ----  this is windows ssh  -----
	@ECHO ssh -t %USER_IP% "cd /d %PUBLISH_PATH% && ssh_win.bat %GIT_USER_KEY% %SRC_PATH% %DST_BRANCH% %EDITION% %NUM% %STARTDATE% 2>&1|tee -a %LOG%"
	@ECHO.
)else (
	@ECHO ----  this is linux ssh  -----
	@ECHO ssh -t %USER_IP% "cd %PUBLISH_PATH%;./ssh_linux.sh %GIT_USER_KEY% %SRC_PATH% %DST_BRANCH% %EDITION% %NUM% 2>&1|tee -a %LOG%" )
	@ECHO.)


:checkfun
IF "%~1" == "" (
	@echo.
	@echo !!! %~2 is NULL !!!
	@echo.
	goto END
)
goto:eof



:END
@echo.
@echo.
pause
exit
