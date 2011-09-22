UDS OnlineEditor 非结构化平台在线编辑控件
Jiangwen Su

重要缺陷
安装wps的机器上，打开文档会打开wps应用程序。

**** 版本说明 ****
v0.3 2011.09.20
	OEGui.dll链接方式改为静态链接，取消对非系统库的依赖。
	修订、批注输出采用json格式。

V0.2 2011.09.15
	OEBuddy.dll改为OEGui.dll，相应地组件OEBuddy.OEBControl改为OEGui.OEGOffice。
	修复bug: 控件嵌入网页后，javascript调用控件接口无反应的问题。
	修复bug: 客户端office文档缺省应用程序设置为wps后，打开文档启动wps应用程序。 应改为启动相应的ms office。
	修复bug: javascript调用控件接口方法时，弹出安全金金警告对话框。
	
V0.1 初始版本 2011.09.13
	提供ActiveX控件OEBuddy.dll，在控件中完全控制Office运行。
	支持Word,Excel,PowerPoint 2003 - 2007，自动识别文档格式。
	接口支持打开、保存、关闭文档
	接口支持获取打开文档的批注信息
	接口支持获取打开文档的修订信息
	接口支持上传UDS服务器

**** 快速运行 ****
运行install.bat
打开网页UDSOnlineEditor Demo.html
接口定义在OEGui.idl中

**** 文件说明 ****

Readme.txt - 本文件
dsoframer.ocx - 微软官方提供的Office嵌入控件
install.bat - 注册安装所有组件的批处理脚本
net.dll - 用于上传文件至UDS服务器的网络组件
OEGui.dll - UDS OnlineEditor主控件
OEGui.idl - UDS OnlineEditor组件接口定义文件
OEGui.tlb - UDS OnlineEditor组件接口定义文件
UDSOnlineEditor Demo.html - 控件嵌入网页的演示
uninstall.bat - 反注册卸载所有组件的批处理脚本


