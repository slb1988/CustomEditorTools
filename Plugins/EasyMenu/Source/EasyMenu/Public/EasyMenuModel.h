#include "Modules/ModuleManager.h"

class FEasyMenuModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
	
