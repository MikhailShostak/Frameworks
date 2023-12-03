#pragma once

class Application
{
public:
	static Application &GetApplication();

	virtual Run() = 0;
};

