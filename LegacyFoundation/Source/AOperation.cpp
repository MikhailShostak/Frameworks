#include ".Foundation.hpp"
#include "AOperation.h"

AOperationDispatcher* DispatcherInstance = nullptr;

PUBLIC_API_EXPORT AOperationDispatcher &getOperationDispatcher()
{
    return *DispatcherInstance;
}

PUBLIC_API_EXPORT void setOperationDispatcher(AOperationDispatcher &Dispatcher)
{
    DispatcherInstance = &Dispatcher;
}
