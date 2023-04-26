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
	//提供初始化
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
		//解析启动状态
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
		//出于安全考虑，已关闭启动项进入开发者模式和测试模式的入口
			// 现在如果需要进入开发者模式和测试模式，需要启动我的个人密钥程序，为了后来的开发者能够方便使用
			// 我将这个 个人密钥 开源到github上去，如果需要可以在在这个目录下获取
			// 未作严格加密，当然了你也可以自制密钥，反正源码都在你手上
			// https://github.com/LeventureQys/Leventure_DevelopKey
			// 
			// Leventure TODO:目前这个进程识别有问题，暂时不适用这个密钥了，直接通过启动项算了

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

