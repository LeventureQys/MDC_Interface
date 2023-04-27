#include "MDC_NetServer.h"

MDC_NetServer::MDC_NetServer(QObject *parent):QObject(parent)
{

}

MDC_NetServer::~MDC_NetServer() {

}

void MDC_NetServer::StartNet()
{
	//开启网络流程如下:
	// 初始化
	//1.启动TCP网络
	//2.开启UDP组播
	//3.向网络中广播当前TCP服务的地址
	//4.等待客户端连接


	



}
bool MDC_NetServer::initNetServer()
{

	return true;

}
void MDC_NetServer::em(const QString&function,const QString& strMessage)
{
	qDebug() << strMessage;
	//emit this->ErrorMessage("MDC_NetServer", "MDC_NetServer", function, strMessage);

}
void MDC_NetServer::Init() {


	if (!this->initLocalLANInterface()) return;

	if (!this->initNetServer()) return;
	
}
bool MDC_NetServer::initLocalLANInterface()
{
	QList<QNetworkInterface> network = QNetworkInterface::allInterfaces();    // 获取所有的接口
	foreach(QNetworkInterface net, network) {
		QNetworkInterface::InterfaceFlags flags = net.flags();
		QString netName = net.humanReadableName();

		QList<QNetworkAddressEntry> list = net.addressEntries(); // 获取IP地址与子网掩码等

		if(flags.testFlag(QNetworkInterface::IsLoopBack) ||
			!flags.testFlag(QNetworkInterface::IsRunning)||
			netName.contains("VM")) {
			continue;
		}

		for (QNetworkAddressEntry address: list) {

			if (address.ip().protocol() == QAbstractSocket::IPv4Protocol) {
				qDebug() << "网卡名：" << netName
					<< " IPv4：" << address.ip().toString()
					<< " 子网掩码：" << address.netmask().toString();

				this->local_network_interface = net;
				qDebug() << "Init Local LAN Interfaces Success!";
				return true;
			}
		}
	}
	qDebug() << "Init Local LAN Interfaces Failed!";
	this->em("initLocalLANInterface", "Init Local LAN Interfaces Failed!");
	return false;
}
;