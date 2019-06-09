#pragma once
#include"AddMsg.h"
#include"DeleteMsg.h"
#include"Urgency.h"
#include"InitialMsg.h"
#include"InquireMsg.h"
#include"ModifyMsg.h"
#include"SortMsg.h"

class app : public student, public colleague, public friends, public relative {
public:
	AddMsg Add;
	DeleteMsg Delete;
	UrgencyMsg Urgency;
	InitialMsg Initial;
	InquireMsg Inquire;
	ModifyMsg Modify;
	SortMsg Sort;
	int showMenu();
};
