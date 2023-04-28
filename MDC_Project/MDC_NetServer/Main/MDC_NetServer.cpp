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
	this->Init();

	



}

void MDC_NetServer::em(const QString& function, const QString& strMessage) {
	emit this->ErrorMessage("MDC_NetServer", "MDC_NetServer", function, strMessage);
}

bool MDC_NetServer::initNetServer()
{
	if (this->bln_init) {
		this->em("initNetServer", "init Already");
		return false;
	}
	
	if (this->ptr_tcp_selfcheck.isNull()) this->ptr_tcp_selfcheck = QSharedPointer<TCPServer>(new TCPServer(this));
	if (this->ptr_tcp_commend.isNull()) this->ptr_tcp_commend = QSharedPointer<TCPServer>(new TCPServer(this));
	if (this->ptr_tcp_file.isNull()) this->ptr_tcp_file = QSharedPointer<TCPServer>(new TCPServer(this));
	
	if (this->ptr_udpserver.isNull()) this->ptr_udpserver = QSharedPointer<UDPServer>(new UDPServer(this));
	bool bln_result = false;
	//服务端只管开启
	if (!this->ptr_tcp_selfcheck.data()->StartTCP(Connection_Type::SelfCheck) ||
		!this->ptr_tcp_commend.data()->StartTCP(Connection_Type::Commend) ||
		!this->ptr_tcp_file.data()->StartTCP(Connection_Type::FileTransfer) ||
		!this->ptr_udpserver.data()->StartNetwork()
		){
		bln_result = false;
		this->em("initNetServer", "connection failed");
		return bln_result;
}

	
	//this->ptr_tcp_selfcheck.data()->

	return true;
}

bool MDC_NetServer::initServerConnect()
{
	

}

void MDC_NetServer::Init() {

	if (!this->initNetServer()) return;
	

}
