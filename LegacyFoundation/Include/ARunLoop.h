#pragma once

#include "AThread.h"
#include "ALog.h"

class PUBLIC_API_EXPORT ARunnable
{
public:

    virtual ~ARunnable() {}
    virtual void onExecute() = 0;

};

class PUBLIC_API_EXPORT ARunLoop
{
    bool running = true;

protected:

    ASemaphore semaphore;
    ARunnable &runnable;

public:

    ARunLoop(ARunnable &runnable):
        semaphore(0),
        runnable(runnable)
    {}

    virtual ~ARunLoop() {}

    virtual void operator ()() final
    {
        execute();
    }

    virtual void execute()
    {
        while(running)
        {
            semaphore.lock();
            runnable.onExecute();
        }
        semaphore.unlock();
    }

    virtual void exit()
    {
        running = false;
        semaphore.unlock();
    }

    void resume()
    {
        semaphore.unlock();
    }

};
