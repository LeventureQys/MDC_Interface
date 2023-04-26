#include "MainApplication.h"

MainApplication::MainApplication(int& argc, char** argv) :
	QApplication(argc, argv)
{
	this->initApplication();
	QList<QString> string_argv;
	for (int i = 0; i < argc; ++i) {
		string_argv.append(QString(argv[i]));
	}

	this->AnalysisArgs(string_argv);
}

MainApplication::~MainApplication()
{

}

void MainApplication::initApplication() {
	//�ṩ��ʼ��
	try {
		if (this->check_pre_instance()) {
			this->nLog("initApplication", "pre_instance already exist!");
			this->mainprocess_quit();
			return;
		}
		this->nLog("initApplication", "check pre instance pass");
		this->init_boot_option();
		this->nLog("initApplication", "init boot option success!");
		this->init_params_object();
		this->nLog("initApplication", "init params object success");

	}
	catch (QException& err) {
		this->eLog("initApplication", err.what());
	}

}

void MainApplication::init_boot_option()
{
	try {
		//��������״̬
		switch (SystemInfo::Singleton()->Dev_Mode)
		{
		case DevState::None:
			break;
		case DevState::Developer_Mode:
			break;
		case DevState::Infomation_Mode:
			break;
		default:
			break;
		}
}
catch (QException& err) {
	this->eLog("init_boot_option", err.what());
}

}

void MainApplication::init_params_object()
{
	try {
		SystemInfo::Singleton();
	}
	catch (QException& err) {
		this->eLog("init_params_object", err.what());
	}
}

void MainApplication::AnalysisArgs(QList<QString> argv)
{
	try {
		//���ڰ�ȫ���ǣ��ѹر���������뿪����ģʽ�Ͳ���ģʽ�����
			// ���������Ҫ���뿪����ģʽ�Ͳ���ģʽ����Ҫ�����ҵĸ�����Կ����Ϊ�˺����Ŀ������ܹ�����ʹ��
			// �ҽ���� ������Կ ��Դ��github��ȥ�������Ҫ�����������Ŀ¼�»�ȡ
			// δ���ϸ���ܣ���Ȼ����Ҳ����������Կ������Դ�붼��������
			// https://github.com/LeventureQys/Leventure_DevelopKey
			// 
			// Leventure TODO:Ŀǰ�������ʶ�������⣬��ʱ�����������Կ�ˣ�ֱ��ͨ������������

		if (argv.contains("Dev")) {
			SystemInfo::Singleton()->Dev_Mode = DevState::Developer_Mode;
		}
	}
	catch (QException& err) {
		this->eLog("AnalysisArgs", err.what());
	}
}

bool MainApplication::check_pre_instance()
{
	try {
		QProcess process;
		process.start("tasklist");
		process.waitForFinished();

		QByteArray result = process.readAllStandardOutput();
		QString str = QString::fromUtf8(result);

		int times = str.count(QApplication::applicationName(), Qt::CaseInsensitive);
		/*int times = str.contains(processName);*/
		if (times > 1)
			return true;
		else
			return false;
	}
	catch (QException& err) {
		this->eLog("check_pre_instance", err.what());
	}
	
}



void MainApplication::mainprocess_quit()
{
	QApplication::exit();
}



void MainApplication::Start() {
	this->initApplication();

}

