#include"AddMsg.h"
#include"DeleteMsg.h"
#include"Urgency.h"
#include"InitialMsg.h"
#include"InquireMsg.h"
#include"ModifyMsg.h"
#include"SortMsg.h"
#include"app.h"

int app::showMenu() {
	char choice;
	while (1) {
		cout << "********** 个人通讯录管理系统 **********\n请输入操作选择\n"
			<< "0: 初始化\t" << "1: 录入\t" << "2: 修改\t" << "3: 查询\t" << "4: 删除\t" << "5.排序\t"
			<< "6.查询紧急电话\t" << "Q: 退出\n";
		cin >> choice;
		switch (choice) {
		case'0':Initial.Initial();break;//初始化
		case'1':Add.Append();break;//添加信息
		case'2':Modify.Modify();break;//修改信息
		case'3':Inquire.Inquire();break;//查询信息
		case'4':Delete.Delete();break;//删除信息
		case'5':Sort.Sort();break;//排序
		case'6':Urgency.Urgency();break;//查询紧急电话
		case'q':
		case'Q':cout << "退出系统\n";
			return 0;
		default:cout << "无效输入，请再输入\n";
		}
	}
}