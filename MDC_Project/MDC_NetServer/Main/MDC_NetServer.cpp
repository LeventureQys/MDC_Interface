#include "MDC_NetServer.h"

MDC_NetServer::MDC_NetServer(QObject *parent):QObject(parent)
{

}

MDC_NetServer::~MDC_NetServer() {

}

void MDC_NetServer::StartNet()
{
	//����������������:
	// ��ʼ��
	//1.����TCP����
	//2.����UDP�鲥
	//3.�������й㲥��ǰTCP����ĵ�ַ
	//4.�ȴ��ͻ�������
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
	//�����ֻ�ܿ���
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
