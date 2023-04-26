#pragma once
//Author:Leventure
//Date:2023-4-23
//Info:�����̣��ý���ֻӦ�ñ�����һ��

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

	void AnalysisArgs(QList<QString> argv); //�������飬������ģʽ���


	void mainprocess_quit();
	//Ѱ����־
	inline void nLog(QString FuncName, QString strValue) {
		South_Tools::WriteNormalMessage(this->metaObject()->className(), FuncName, strValue);
	}
	//�쳣��־
	inline void eLog(QString FuncName, QString strValue) {
		South_Tools::WriteErrorMessage(this->metaObject()->className(), FuncName, strValue);
	}

	QSharedPointer<QThread> thread_tcp;
	QSharedPointer<QThread> thread_file;
};
