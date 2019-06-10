#pragma once
#include"msg.h"

//删除信息类，继承学生，同事，朋友，亲戚类
class DeleteMsg :public File{
public:
	void Delete();//删除信息函数
};