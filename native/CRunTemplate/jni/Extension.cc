
#include <NativeExtension.h>
#include <alloca.h>

void Extension::init ()
{

}

struct EDITDATA
{
    /* Copy the members of edPtr here */
    
};

int Extension::getNumberOfConditions ()
{
    return 0;
}

Extension::Extension (EDITDATA * edPtr, void * _ext, RuntimeFunctions &_Runtime)
        : Runtime (_Runtime), ext (_ext)
{
    /* Use as createRunObject */
 

}

Extension::~Extension ()
{
    /* Use as destroyRunObject */
    
}

int Extension::handleRunObject ()
{
    
    return REFLAG_ONESHOT;
}

void Extension::action (int num, Action &act)
{
}

bool Extension::condition (int num, Condition &cnd)
{
    return true;
}

void Extension::expression (int num, Expression &exp)
{

}




