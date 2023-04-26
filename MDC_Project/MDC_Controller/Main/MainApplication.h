#pragma once
//Author:Leventure
//Date:2023-4-23
//Info:主进程，该进程只应该被启动一次

//try {
//
//}
//catch (QException& err) {
//	
//}
#include <QApplication>
#include "qapplication.h"
#include "../Tools/Tools_South.h"
#include "../LocalInfo/SystemInfo.h"
#include "qlist.h"
class MainApplication  : public QApplication
{
	Q_OBJECT

public:
	MainApplication(int& argc, char** argv);
	~MainApplication();
	
	void Start();

private:


	void initApplication();

	void init_boot_option();
	void init_params_object();
	bool check_pre_instance();

	void AnalysisArgs(QList<QString> argv); //启动项检查，开发者模式检查


	void mainprocess_quit();
	//寻常日志
	inline void nLog(QString FuncName, QString strValue) {
		South_Tools::WriteNormalMessage(this->metaObject()->className(), FuncName, strValue);
	}
	//异常日志
	inline void eLog(QString FuncName, QString strValue) {
		South_Tools::WriteErrorMessage(this->metaObject()->className(), FuncName, strValue);
	}

	QSharedPointer<QThread> thread_tcp;
	QSharedPointer<QThread> thread_file;
};
